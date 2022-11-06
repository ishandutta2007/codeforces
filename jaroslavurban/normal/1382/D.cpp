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


const int N=2020;
bool dp[2*N][2*N];
vector<int>l;
int a[2*N];
int main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		for(int i=0;i<2*n;++i)cin>>a[i];
		l.clear();
		int mx=0,last=0;
		for(int i=0;i<2*n;++i){
			if(i&&a[i]>mx){
				l.push_back(i-last);
				last=i;
			}
			mx=max(mx,a[i]);
		}
		l.push_back(2*n-last);
		for(int i=0;i<2*n;++i)
			for(int j=0;j<=l.size();++j)
				dp[i][j]=false;
		dp[0][0]=true;
		for(int i=0;i<2*n;++i)
			for(int j=0;j<l.size();++j)
				if(dp[i][j]){
				dp[i][j+1]=true;
				dp[i+l[j]][j+1]=true;
			}
		if(dp[n][l.size()])cout<<"YES\n";
		else cout<<"NO\n";
	}
}