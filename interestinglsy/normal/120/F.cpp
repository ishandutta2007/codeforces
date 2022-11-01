#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <cstring>
#include <vector>
#define ll long long
#define ull unsigned ll
#define uint unsigned int
#define pb push_back
#define ms(a) memset(a,0,sizeof(a))
using namespace std;

int n;
int m;
vector<int> data[208];
int froms[108],tos[208];

bool past[208];
int farthests[208];	//farthests[i]i
int maxd;	//
void dfs(int pos){
	past[pos] = 1;
	int farthest = 0;
	for(int i = 0;i < data[pos].size();i++){
		if(past[data[pos][i]] == 1) continue;
		dfs(data[pos][i]);
		int far = farthests[data[pos][i]]+1;
		if(far > farthest)
			farthest = far;
	}
	farthests[pos] = farthest;
	maxd = max(maxd,farthest);
}
ll maxdis(){
	int ret = 0;
	for(uint j = 1;j < m;j++){
		ms(past);ms(farthests);
		past[froms[j]] = 1;
		maxd = 0;
		dfs(tos[j]);
		int d1 = maxd;
		
		ms(past);ms(farthests);
		past[tos[j]] = 1;
		maxd = 0;
		dfs(froms[j]);
		int d2 = maxd;
		
		ret = max(ret,d1+d2+1);
	}
	return ret;
}
///////////////////////////////////////////////////////////////////////
void addedge(int f,int t,int ii){
	data[f].pb(t);
	data[t].pb(f);
	froms[ii] = f;
	tos[ii] = t;
}
///////////////////////////////////////////////////////////////////////
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	ll allans = 0;
	cin >> n;
	for(uint ni = 1;ni <= n;ni++){
		cin >> m;
		for(uint i = 0;i <= m;i++)
			data[i].clear();
		for(uint i = 1;i < m;i++){
			int f,t;
			cin >> f >> t;
			addedge(f,t,i);
		}
		allans +=  maxdis();
	}
	
	cout << allans << endl;
	
	return 0;
}