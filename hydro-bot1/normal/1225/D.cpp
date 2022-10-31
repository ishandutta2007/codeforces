// Hydro submission #62860b318adeacb301bd7294@1652951858254
#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "algorithm"
#include "cmath"
#include "vector"
#include "map"
using namespace std;
#define LL long long
map<vector<pair<int,int> >, int> mp;
int n,k,a; LL ans;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a);
		vector <pair<int,int> > c,cc;
		for(int j=2;j<=sqrt(a);++j){
			int t=0;
			while(a%j==0){
				if(++t>=k)t-=k;
				a/=j;
			}
			if(!t)continue;
			c.push_back({j,t});
			cc.push_back({j,k-t});
		}
		if(a!=1){
			c.push_back({a,1});
			cc.push_back({a,k-1});
		}
		ans+=mp[cc];
		++mp[c];
	}
	printf("%lld\n",ans);
	return 0;
}