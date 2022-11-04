#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);

#define mod 998244353

string s,t;
// left to the left,total added;
ll dp[3001][3001];
int main(){
	cin>>s>>t;
	int n=s.size(),m=t.size();
	for(int i=0;i<=n;++i)dp[i][0]=1;
	for(int i=n;i>=0;--i)
		for(int j=0;j<n;++j){
			int r=i+j;
			if(r<n&&(r>=m||s[j]==t[r]))dp[i][j+1]=(dp[i][j+1]+dp[i][j])%mod;
			if(i&&((i<=m&&s[j]==t[i-1])||i>m))dp[i-1][j+1]=(dp[i-1][j+1]+dp[i][j])%mod;
		}
	ll res=0;
	for(int j=m;j<=n;++j)res=(res+dp[0][j])%mod;
	cout<<res<<endl;
}