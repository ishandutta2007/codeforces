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
	int t;cin>>t;
	for(int tc=0;tc<t;++tc){
		int n,a,b,c;cin>>n>>a>>b>>c;
		int aa=0,bb=0,cc=0;
		string s;cin>>s;
		for(int i=0;i<n;++i)
			if(s[i]=='R')++aa;
			else if(s[i]=='P')++bb;
			else if(s[i]=='S')++cc;
		int won=min(a,cc)+min(b,aa)+min(c,bb);
		if(won*2<n)cout<<"NO\n";
		else{
			cout<<"YES\n";
			int la=a-min(a,cc),lb=b-min(b,aa),lc=c-min(c,bb);
			a=min(a,cc);b=min(b,aa);c=min(c,bb);
			for(int i=0;i<n;++i){
				if(s[i]=='R'&&b){cout<<'P';--b;}
				else if(s[i]=='S'&&a){cout<<'R';--a;}
				else if(s[i]=='P'&&c){cout<<'S';--c;}
				else if(la){cout<<'R';--la;}
				else if(lb){cout<<'P';--lb;}
				else if(lc){cout<<'S';--lc;}
			}
			cout<<endl;
		}
	}
}