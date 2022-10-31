#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
double a[1000005],b[1000005],l,r,md,res,mn,sb;

int main() {
	ios::sync_with_stdio(0);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		
		l=0;r=2e8;res=2e8;
		
		for(i=1;i<=n;i++){
			scanf("%lf",&a[i]);
		}
		for(i=1;i<=n;i++){
			scanf("%lf",&b[i]);
			l=max(l,b[i]);
		}
		
		for(int T=1;T<=60;T++){
			vector<pair<double,double> >v;
			mn=1e9;
			md=(l+r)/2;
			for(i=1;i<=n;i++){
				v.push_back({a[i]-(md-b[i]),a[i]+(md-b[i])});
			}
			sort(v.begin(),v.end());
			
			for(auto [i,j]:v){
				if(mn<=i){
					l=md;goto aaa;
				}
				mn=min(mn,j);
			}
			if(res>md){
				res=md;sb=mn;
			}
			r=md;
			aaa:;
		}
		
		printf("%.20lf\n",sb);
	}
}