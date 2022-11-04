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

int n;
string s;
int dfs(int c,int l,int r){
	if(r-l==1)return s[l]!='a'+c;
	int lp=0,rp=0,m=(l+r)/2;
	for(int i=l;i<r;++i)if(s[i]!='a'+c)if(i<m)++lp;else ++rp;
	return min(lp+dfs(c+1,m,r),rp+dfs(c+1,l,m));
}
int main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int t;cin>>t;
	while(t--){
		cin>>n>>s;
		cout<<dfs(0,0,n)<<endl;
	}
}