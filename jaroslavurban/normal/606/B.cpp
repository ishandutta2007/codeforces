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

const int N=550;
int x,y;
bool vis[N][N];
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int x0=0,y0=0;
	cin>>x>>y>>x0>>y0;
	--x0;--y0;
	string s;cin>>s;
	int n=s.size();
	cout<<"1 ";
	vis[x0][y0]=true;
	int total=1;
	for(int i=0;i<n-1;++i){
		if(s[i]=='U'&&x0)--x0;
		if(s[i]=='D'&&x0<x-1)++x0;
		if(s[i]=='L'&&y0)--y0;
		if(s[i]=='R'&&y0<y-1)++y0;
		if(vis[x0][y0])cout<<"0 ";
		else {
			cout<<"1 ";
			++total;
		}
		vis[x0][y0]=true;
	}
	cout<<x*y-total<<endl;
}