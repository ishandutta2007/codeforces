#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c)){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 3e5 + 10;
vector < int > Edge[MAXN];
int sumX , sumY , M , N , x[MAXN] , y[MAXN] , ind[MAXN] , ans[MAXN];
bool vis[MAXN];

bool cmp(int a , int b){
	return x[a] - y[a] < x[b] - y[b];
}

signed main(){
#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
#endif
	N = read();
	M = read();
	for(int i = 1 ; i <= N ; ++i){
		x[i] = read();
		y[i] = read();
		sumY += y[i];
		ind[i] = i;
	}
	for(int i = 1 ; i <= M ; ++i){
		int a = read() , b = read();
		Edge[a].push_back(b);
		Edge[b].push_back(a);
	}
	
	sort(ind + 1 , ind + N + 1 , cmp);
	for(int i = 1 ; i <= N ; ++i){
		sumY -= y[ind[i]];
		vis[ind[i]] = 1;
		ans[ind[i]] = sumX + sumY + (i - 1) * y[ind[i]] + (N - i) * x[ind[i]];
		for(int j = 0 ; j < Edge[ind[i]].size() ; ++j)
			if(vis[Edge[ind[i]][j]])
				ans[ind[i]] -= x[Edge[ind[i]][j]] + y[ind[i]];
			else
				ans[ind[i]] -= y[Edge[ind[i]][j]] + x[ind[i]];
		sumX += x[ind[i]];
	}
	for(int i = 1 ; i <= N ; ++i)
		cout << ans[i] << ' ';
	return 0;
}