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
	ll n,k;cin>>n>>k;	
	string s,t;cin>>s;
	t=s;
	int b=0;
	for(int i=0;i+k<n;++i){
		if(s[i]<s[i+k]&&!b)b=-1;
		else if(s[i]>s[i+k]&&!b)b=1;
		s[i+k]=s[i];
	}
	if(b>=0){
		cout<<n<<endl;
		cout<<s<<endl;
		return 0;
	}
	int c=1;
	s=t;
	for(int i=k-1;i>=0&&c;--i)
		if(s[i]=='9')s[i]='0';
		else {++s[i];cerr<<i<<endl;c=0;}
	if(c)s.insert(0,"1");
	for(int i=0;i+k<n;++i)s[i+k]=s[i];
	cout<<s.size()<<endl;
	cout<<s<<endl;
}