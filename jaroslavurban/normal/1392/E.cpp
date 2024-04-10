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

const int N=27;
ll f[N][N];
int n;
ll sm;
vector<pair<int,int>>pairs;
bool dfs(int y,int x,ll num){
	if(y==n-1&&x==n-1&&(f[y][x]|num)==sm){
		pairs.push_back({y,x});
		return true;
	}
	if(y%2&&x+1<n&&(!f[y][x+1]||(f[y][x+1]&sm))){
		if(dfs(y,x+1,num|f[y][x])){
			pairs.push_back({y,x});
			return true;
		}
	}
	if(y+1<n&&(!f[y+1][x]||(f[y+1][x]&sm))){
		if(dfs(y+1,x,num|f[y][x])){
			pairs.push_back({y,x});
			return true;
		}
	}
	if(y%2==0&&x+1<n&&(!f[y][x+1]||(f[y][x+1]&sm))){
		if(dfs(y,x+1,num|f[y][x])){
			pairs.push_back({y,x});
			return true;
		}
	}
	return false;
}
	
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<n;i+=2)
		for(int j=0;j<n;++j)
			f[i][j]=(1ll<<(i-1+j));
	for(int i=0;i<n;++i,cout<<endl)
		for(int j=0;j<n;++j)
			cout<<f[i][j]<<" ";
	ll q;
	cin>>q;
	while(q--){
		cin>>sm;
		assert(dfs(0,0,0));
		for(int i=n+n-2;i>=0;--i)cout<<pairs[i].first+1<<" "<<pairs[i].second+1<<endl;
		pairs.clear();
	}
}