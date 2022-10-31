#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		int q;
		cin>>n>>m>>q>>s;
		s="X"+s;
		ll sb=n,l,r;
		vector<tuple<ll,ll,ll,ll> >v;
		for(i=1;i<=m;i++){
			cin>>l>>r;
			v.push_back({sb+1,sb+r-l+1,l,r});
			sb+=r-l+1;
		}
		while(q--){
			cin>>sb;
			while(sb>n){
				for(auto [a,b,c,d]:v){
					if(sb>=a&&sb<=b){
						//printf("NMSL%d %d %d %d %d\n",sb,a,b,c,d);
						sb=sb-a+c;break;
					}
				}
			}
			cout<<s[sb]<<'\n';
		}
	}
}