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

string s,q="abacaba";
int n,m=q.size();
int cnt(){
	int c=0;
	for(int i=0;i+m-1<n;++i){
		bool pos=true;
		for(int j=0;j<m;++j)if(s[i+j]!=q[j])pos=false;
		c+=pos;
	}
	return c;
}
	
int main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n>>s;
		bool cc=false;
		for(int i=0;i+m-1<n;++i){
			bool can=true;
			for(int j=0;j<m;++j)if(s[i+j]!='?'&&s[i+j]!=q[j])can=false;
			if(!can)continue;
			string t=s;
			for(int j=0;j<m;++j)s[i+j]=q[j];
			if(cnt()==1){
				cc=true;
				break;
			}
			s=t;
		}
		if(cc){cout<<"Yes\n";for(int i=0;i<n;++i)if(s[i]=='?')cout<<'f';else cout<<s[i];
		cout<<endl;}
		else cout<<"No\n";
	}
}