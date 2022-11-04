#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

const int N=510;
int a[N][N],b[N][N];
int n,m;
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			cin>>a[i][j];
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			cin>>b[i][j];
	bool pos=true;
	for(int i=0;i<n;++i){
		int cntm=0;
		for(int j=0;j<m;++j)
			if(a[i][j]!=b[i][j])++cntm;
		if(cntm%2)pos=false;
	}
	for(int i=0;i<m;++i){
		int cntm=0;
		for(int j=0;j<n;++j)
			if(a[j][i]!=b[j][i])++cntm;
		if(cntm%2)pos=false;
	}
	if(pos)cout<<"Yes\n";
	else cout<<"No\n";
}