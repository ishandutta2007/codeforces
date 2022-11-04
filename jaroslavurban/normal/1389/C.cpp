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

string s;
int n;
int solve(int u,int v){
	bool uu=true;
	int idx=0;
	int len=0;
	while(idx<n){
		if(uu)while(idx<n&&s[idx]-'0'!=u)++idx;
		if(!uu)while(idx<n&&s[idx]-'0'!=v)++idx;
		if(idx<n)++len;
		++idx;
		uu=!uu;
	}
	if(u!=v&&len%2)return len-1;
	return len;
}
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>s;
		n=s.size();
		int res=0;
		for(int i=0;i<10;++i)
			for(int j=0;j<10;++j)
				res=max(solve(i,j),res);
		cout<<n-res<<endl;
	}
}