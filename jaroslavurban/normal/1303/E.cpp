#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

string s,t;
const int N=444;
int n,m,n1,n2;
int dp[N][N];
bool is[26];
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	outer: while(tc--){
		memset(is,0,sizeof(is));
		cin>>s>>t;
		int n=s.size(),m=t.size();
		for(int i=0;i<=m;++i){
			n1=i;n2=m-i;
			for(int i=0;i<=n1;++i)
				for(int j=0;j<=n2;++j){
					int mn=1e9;
					if(i)
						for(int k=dp[i-1][j];k<n;++k)if(s[k]==t[i-1]){
							mn=min(mn,k+1);
							break;
						}
					if(j)
						for(int k=dp[i][j-1];k<n;++k)if(s[k]==t[n1+j-1]){
							mn=min(mn,k+1);
							break;
						}
					dp[i][j]=(i||j)*mn;
				}
			if(dp[n1][n2]!=1e9){
				cout<<"YES\n";
				goto outer;
			}
		}
		cout<<"NO\n";
	}
}