#include<bits/stdc++.h>
#define eb emplace_back
#define ll long long
using namespace std;
int n;
vector<ll>d[2];
void work(){
	d[0].clear();
	d[1].clear();
	scanf("%d",&n);
	for(ll i=1,x,y;i<=n*2;++i){
		scanf("%lld%lld",&x,&y);
		if(x==0)d[0].eb(abs(y));
		else d[1].eb(abs(x));
	}
	sort(d[0].begin(),d[0].end());
	sort(d[1].begin(),d[1].end());
	long double ans=0;
	for(int i=0;i<n;++i)ans+=sqrt(d[0][i]*d[0][i]+d[1][i]*d[1][i]);
	printf("%.10Lf\n",ans); 
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}