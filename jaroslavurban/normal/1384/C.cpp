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

const int N=20;
const int inf=10000000;
int n;
string a,b;
int dp[N][N];
int main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n>>a>>b;
		memset(dp,0,sizeof(dp));
		bool pos=true;
		for(int i=0;i<n;++i)
			if(a[i]>b[i])pos=false;
			else if(a[i]<b[i])++dp[a[i]-'a'][b[i]-'a'];
		if(!pos){
			cout<<-1<<endl;
			continue;
		}
		int res=0;
		for(int i=0;i<N;++i){
			int mn=inf;
			for(int j=0;j<N;++j)if(dp[i][j]){mn=j;break;}
			if(mn!=inf){
				for(int j=mn+1;j<N;++j)dp[mn][j]+=dp[i][j];
				++res;
			}
		}
		cout<<res<<endl;

	}
}