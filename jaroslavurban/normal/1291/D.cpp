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

const int N=200100,A=26;
string s;
int q,n;
int pre[N][A];
int main(){
	cin>>s>>q;
	n=s.size();
	for(int i=1;i<=n;++i){
		++pre[i][s[i-1]-'a'];
		for(int j=0;j<A;++j)pre[i][j]+=pre[i-1][j];
	}
	for(int i=0;i<q;++i){
		int a,b;cin>>a>>b;
		if(a==b)cout<<"Yes"<<endl;
		else{
			int cnt=0;
			for(int j=0;j<A;++j)if(pre[b][j]-pre[a-1][j]>0)++cnt;
			if(cnt>2||s[a-1]!=s[b-1])cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
}