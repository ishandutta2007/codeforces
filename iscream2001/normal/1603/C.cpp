#include <bits/stdc++.h>
using namespace std;
#define LL unsigned long long
const int N=3e5+10;
const LL P=998244353;
int n,K;
int a[N];
vector< pair<LL,LL> > V[2];
void MAIN(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	V[0].clear();
	V[1].clear();
	LL ans=0;
	
	int x,y,z;
	LL re;
	for(int i=n;i>=1;--i){
		//cout<<"now "<<ans<<endl;
		int it=V[0].size()-1;
		for(int l=1,r;l<=a[i];l=r+1){
			x=a[i]/l;
			r=a[i]/x;
			y=a[i]-x*l;
			re=0;
			if(y) z=x+1;
			else z=x;
			//cout<<x<<" "<<z<<endl;
			while(it>=0&&z<=V[0][it].first){
				(ans+=V[0][it].second*(LL)(l-1)*(LL)i)%=P;
				re+=V[0][it].second;
				--it;
			}
			y=a[i]-x*r;
			if(y) z=x+1;
			else z=x;
			while(it>=0&&z<=V[0][it].first){
				(ans+=V[0][it].second*(LL)(r-1)*(LL)i)%=P;
				re+=V[0][it].second;
				--it;
			}
			V[1].push_back(make_pair((LL)x,re%P));
		}
		V[0].clear();
		for(int j=V[1].size()-1;j>=0;--j){
			V[0].push_back(V[1][j]);
		}
		V[1].clear();
		V[0].push_back(make_pair(a[i],(LL)1));
	}
	printf("%lld\n",ans);
	return;
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		MAIN();
	}
    return 0;
}