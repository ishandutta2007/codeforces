#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int INF=0x3f3f3f3f;
int n,m;
int a[N];
typedef pair<int,int> pii;
int l[N],r[N],t[N];
pii rk[N];
int cnt;
int cut[N];
int ql[N],qr[N];
int LL[N],RR[N],mx[N],mn[N];
vector<int>ansq;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&l[i],&r[i]);
		rk[++cnt]=pii(l[i]-1,-i);
		rk[++cnt]=pii(r[i],i);
	}
	sort(rk+1,rk+cnt+1);
	int tm=0;
	LL[1]=1;
	for(int i=1;i<=cnt;i++){
		if(rk[i].first==0){
			ql[-rk[i].second]=1;
			continue;
		}
		if(i==1||rk[i].first!=rk[i-1].first)++tm;
		LL[tm+1]=rk[i].first+1;RR[tm]=rk[i].first;
		if(rk[i].second<0)ql[-rk[i].second]=tm+1;
		else qr[rk[i].second]=tm;
	}
	if(RR[tm]<n)RR[++tm]=n;
	for(int i=1;i<=tm;i++){
		mx[i]=-INF,mn[i]=INF;
		for(int j=LL[i];j<=RR[i];j++){
			mx[i]=max(mx[i],a[j]);
			mn[i]=min(mn[i],a[j]);
		}
		// cout<<LL[i]<<" "<<RR[i]<<"<"<<mx[i]<<","<<mn[i]<<endl;
	}
	// for(int j=1;j<=m;j++){
	// 	cout<<ql[j]<<"-"<<qr[j]<<endl;
	// }
	int ans=0;
	for(int i=1;i<=tm;i++){
		int MX=mx[i];
		vector<int>newans;
		for(int j=1;j<=m;j++){
			if(ql[j]<=i&&qr[j]>=i)continue;
			newans.push_back(j);
			for(int k=ql[j];k<=qr[j];k++)mn[k]--;
		}
		int MN=INF;
		for(int j=1;j<=tm;j++)MN=min(MN,mn[j]);
		for(int j=1;j<=m;j++){
			if(ql[j]<=i&&qr[j]>=i)continue;
			for(int k=ql[j];k<=qr[j];k++)mn[k]++;
		}
		if(MX-MN>ans)ansq=newans;
		ans=max(ans,MX-MN);
	}
	cout<<ans<<endl;
	cout<<ansq.size()<<endl;
	for(size_t i=0;i<ansq.size();i++){
		printf("%d ",ansq[i]);
	}puts("");
}