#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define N 100000
int i,j,k,n,m,t,p[100500],a[100500],b[100500],c[100500];
vector<pair<int,int> > q[100500];
vector<int> v[100500];
ll res;

int main() {
	ios::sync_with_stdio(0);
	for(i=2;i<=N;i++){
		if(!p[i])for(j=i;j<=N;j+=i){
			if(!(j%(1ll*i*i)))p[j]=-1e5;
			p[j]++;
		}
		if(p[i]>0){
			for(j=i;j<=N;j+=i){
				q[j].push_back({i,(p[i]&1)?1:-1});
			}
		}
	}
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>k;
		res=max(res,1ll*k);
		a[k]=1;
	}
	for(i=1;i<=N;i++){
		if(clock()*1.0/CLOCKS_PER_SEC>0.9999)break;
		m=N/i;
		memset(c,0,m*4+50);
		for(j=1;j<=m;j++){
			b[j]=a[j*i];
		}
		for(j=1;j<=m;j++){
			if(p[j]<=0)continue;
			for(k=j;k<=m;k+=j){
				if(b[k]){
					v[j].push_back(k);
				}
			}
		}
		for(j=m;j>=1;j--){
			c[j]=c[j+1]+b[j];
		}
		for(j=1;j<=m;j++){
			if(!b[j])continue;
			int l,r,md,su,ans=m+1;
			l=1,r=m;
			while(l<=r){
				md=(l+r)/2;
				su=0;
				for(auto [x,y]:q[j]){
					if(v[x].empty())continue;
					su+=y*(v[x].end()-lower_bound(v[x].begin(),v[x].end(),md));
				}
				if(su==c[md]){
					ans=min(ans,md);r=md-1;
				}
				else l=md+1;
			}
			ans--;
			res=max(res,1ll*i*j*ans);
		}
		for(j=1;j<=m;j++){
			vector<int> clr;
			swap(v[j],clr);
			b[j]=0;
		}
	}
	cout<<res;
}