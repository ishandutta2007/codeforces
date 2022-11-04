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

const int N=222;
int n,t;
int a[N][N];

bool update(){
	bool res=false;
	for(int i=1;i<N-1;++i)
		for(int j=1;j<N-1;++j)
			if(a[i][j]>=4){
				res=true;
				a[i+1][j]+=a[i][j]/4;
				a[i-1][j]+=a[i][j]/4;
				a[i][j+1]+=a[i][j]/4;
				a[i][j-1]+=a[i][j]/4;
				a[i][j]=a[i][j]%4;
			}
	return res;
}

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>t;
	a[N/2][N/2]=n;
	while(update()){}
	while(t--){
		int x,y;cin>>x>>y;
		x+=N/2;y+=N/2;
		if(x<N&&y<N&&x>=0&&y>=0)cout<<a[y][x]<<'\n';
		else cout<<0<<'\n';
	}
}