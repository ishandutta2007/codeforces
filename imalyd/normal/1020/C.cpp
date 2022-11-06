#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m,is[N],cnt[N],cnt2[N];
struct voter{int id,v;}vot[N];
bool cmp(voter a,voter b){return a.v<b.v;}
long long ans=1ll<<62;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		++cnt[a];
		if(a==1)--n,--i;
		else vot[i]=(voter){a,b};
	}
	sort(vot+1,vot+n+1,cmp);
	//for(int i=1;i<=n;i++)printf("%d %d\n",vot[i].id,vot[i].v);
	for(int i=1;i<=cnt[1]+n;i++){
		memset(is,0,sizeof(is));
		int need=i-cnt[1];long long cal=0;
		for(int j=2;j<=m;j++)cnt2[j]=cnt[j]-i;
		//for(int j=2;j<=m;j++)printf("> %d\n",cnt2[j]);
		for(int j=1;j<=n;j++){
			int id=vot[j].id;
			if(0<=cnt2[id])--cnt2[id],--need,is[j]=1,cal+=vot[j].v;//printf("choose1 %d\n",j);
		}
		if(0<need){
			for(int j=1;j<=n;j++)if(!is[j]){
				is[j]=1,cal+=vot[j].v,--need;//printf("choose2 %d\n",j);
				if(!need)break;
			}
		}//
		ans=min(ans,cal);
	}
	cout<<ans;
}