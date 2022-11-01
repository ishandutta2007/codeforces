#include <bits/stdc++.h>
#define maxn 1086

using namespace std;

int n, m;
vector<tuple<int, int, int> > v;
bool tag[maxn][maxn];
int a[maxn][maxn];
queue<tuple<int, int, int> > q;

void cal(int i, int j){
	if(!(i >= 1 && i < n && j >= 1 && j < m)) return;
	if(tag[i][j]) return;
	int x = -1;
	int y = a[i][j];
	if(y != -1){
		if(x == -1) x = y;
		else if(x ^ y) return;
	}
	y = a[i + 1][j];
	if(y != -1){
		if(x == -1) x = y;
		else if(x ^ y) return;
	}
	y = a[i][j + 1];
	if(y != -1){
		if(x == -1) x = y;
		else if(x ^ y) return;
	}
	y = a[i + 1][j + 1];
	if(y != -1){
		if(x == -1) x = y;
		else if(x ^ y) return;
	}
	tag[i][j] = true;
	if(x != -1) q.push(make_tuple(i, j, x));
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) scanf("%d", &a[i][j]);
	for(int i = 1;i < n;i++) for(int j = 1;j < n;j++) cal(i, j);
	while(!q.empty()){
		tuple<int, int, int> t = q.front();q.pop();
		v.push_back(t);
		int i = get<0>(t), j = get<1>(t);
		a[i][j] = a[i + 1][j] = a[i][j + 1] = a[i + 1][j + 1] = -1;
		for(int ii = -1;ii <= 1;ii++) for(int jj = -1;jj <= 1;jj++) cal(i + ii, j + jj);
	}
	for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) if(a[i][j] != -1) return printf("-1"), 0;
	printf("%d\n", v.size());
	for(int i = v.size() - 1;~i;i--) printf("%d %d %d\n", get<0>(v[i]), get<1>(v[i]), get<2>(v[i]));
}