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

int main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		string s,t;cin>>s>>t;
		int n=s.size(),m=t.size();
		char prev='#';
		int i=0,j=0;
		bool pos=true;
		while(i<n){
			while(j<m&&s[i]!=t[j]&&t[j]==prev)++j;
			if(j==m)break;
			if(s[i]!=t[j]){pos=false;break;}
			prev=s[i];
			++i;++j;
		}
		if(pos)for(;j<m;++j)if(t[j-1]!=t[j])pos=false;
		if(i<n)pos=false;
		if(pos)cout<<"YES\n";
		else cout<<"NO\n";
	}
}