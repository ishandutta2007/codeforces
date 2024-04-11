#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

struct qry{
	int sx, ex, sy, ey, idx;
};

int n, m;
char str[505][505];
int up[505][505];
bool ret[600004];

bitset<505> l[505][505], r[505][505];

void solve(int s, int e, vector<qry> &q){
	if(s == e){
		for(auto &i : q){
			ret[i.idx] = (up[i.ex][s] < i.sx);
		}
		return;
	}
	int m = (s+e)/2;
	for(int i=0; i<n; i++){
		l[i][m+1].reset();
		r[i][m].reset();
		l[i][m+1].set(i);
		r[i][m].set(i);
	}
	for(int i=m+1; i<=e; i++){
		for(int j=0; j<n; j++){
			r[j][i] = r[j][i-1];
			if(j) r[j][i] |= r[j-1][i];
			if(str[j][i] == '#') r[j][i].reset();
		}
	}
	for(int i=m; i>=s; i--){
		for(int j=n-1; j>=0; j--){
			l[j][i] = l[j][i+1] | l[j+1][i];
			if(str[j][i] == '#') l[j][i].reset();
		}
	}
	vector<qry> q1, q2;
	for(auto &i : q){
		if(i.sy <= m && i.ey > m){
			ret[i.idx] = (l[i.sx][i.sy] & r[i.ex][i.ey]).any();
		}
		else if(i.ey <= m) q1.push_back(i);
		else q2.push_back(i);
	}
	solve(s, m, q1);
	solve(m+1, e, q2);
}

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++) cin >> str[i];
	vector<qry> query;
	int q;
	cin >> q;
	for(int i=0; i<q; i++){
		qry t;
		scanf("%d %d %d %d",&t.sx,&t.sy,&t.ex,&t.ey);
		t.sx--, t.sy--, t.ex--, t.ey--;
		t.idx = i;
		query.push_back(t);
	}
	for(int i=0; i<m; i++){
		up[0][i] = (str[0][i] == '#' ? 0 : -1);
	}
	for(int i=1; i<n; i++){
		for(int j=0; j<m; j++){
			up[i][j] = (str[i][j] == '#' ? i : up[i-1][j]);
		}
	}
	solve(0, m-1, query);
	for(int i=0; i<q; i++){
		puts(ret[i] ? "Yes" : "No");
	}
}