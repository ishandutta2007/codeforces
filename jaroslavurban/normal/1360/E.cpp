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

char pol[50][51];
int n;

int main(){
	int t;cin>>t;
	for(int i=0;i<t;++i){
		cin>>n;
		for(int i=0;i<n;++i)cin>>pol[i];
		bool fl=true;
		for(int i=0;i<n-1;++i)
			for(int j=0;j<n-1;++j)
				if(pol[i][j]=='1'&&pol[i+1][j]=='0'&&pol[i][j+1]=='0')
					fl=false;
		if(fl)cout<<"YES\n";
		else cout<<"NO\n";
	}
}