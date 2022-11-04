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

const int N=200010;
int n;
int a[N],b[N];
vector<int>in[N];
bool uup[N];
int res=0;
vector<int>r;

void up(int u){
	if(uup[u])return;
	uup[u]=true;
	res+=a[u];
	r.push_back(u);
	for(auto v:in[u])up(v);
}

int dfs(int u){
	for(auto v:in[u])a[u]+=dfs(v);
	if(a[u]>0)up(u);
	return max(a[u],0ll);
}

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i){
		cin>>b[i];
		if(b[i]==i+1)b[i]=-1;
		if(~b[i])in[--b[i]].push_back(i);
	}
	for(int i=0;i<n;++i)if(b[i]==-1){dfs(i);up(i);}
	cout<<res<<endl;
	for(auto u:r)cout<<u+1<<" ";
	cout<<endl;
}