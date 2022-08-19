#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using lint = long long;
const int MAXN = 1005;

int n, m, p[33];

int query(int x){
	cout << x << endl;
	int v; cin >> v;
	if(v == 0){
		exit(0);
	}
	else return v;
}
int main(){
	cin >> m >> n;
	for(int i=0; i<n; i++) p[i] = query(1);
	int st = 1, ed = m;
	int ptr = 0;
	while(st != ed){
		int m = (st + ed) / 2;
		int ans = query(m);
		if(p[ptr] == -1) ans = -ans;
		if(ans < 0) ed = m - 1;
		else st = m + 1;
		ptr = (ptr + 1) % n;
	}
	query(st);
}