#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

vector<int> a, b, c;
int d1[105][105];

int f1(int x, int y){
	if(x == a.size() || y == c.size()) return 0;
	if(~d1[x][y]) return d1[x][y];
	int ret = max(f1(x, y+1), f1(x+1, y));
	if(a[x] <= c[y]) ret = max(ret, f1(x+1, y+1) + c[y] - a[x]);
	return d1[x][y] = ret;
}

int d2[105][105][105];
int d3[105][105][105];

int f2(int x, int y, int z){
	if(x > a.size() || y > b.size() || z > c.size()) return -1e9;
	if(z == c.size()){
		if(y == b.size()) return 0;
		return -1e9;
	}
	if(~d2[x][y][z]) return d2[x][y][z];
	int ret = max(f2(x+1, y, z), f2(x, y, z+1));
	if(x < a.size() && z < c.size() && a[x] <= c[z]){
		ret = max(ret, f2(x+1, y, z+1) + c[z] - a[x]);
	}
	if(y < b.size() && z < c.size() && b[y] < c[z]){
		ret = max(ret, f2(x, y+1, z+1));
	}
	return d2[x][y][z] = ret;
}

int f3(int x, int y, int z){
	if(x > a.size() || y > b.size() || z > c.size()) return -1e9;
	if(z == c.size()){
		if(y == b.size() && x == a.size()) return 0;
		return -1e9;
	}
	if(~d3[x][y][z]) return d3[x][y][z];
	int ret = f3(x, y, z+1) + c[z];
	if(x < a.size() && z < c.size() && a[x] <= c[z]){
		ret = max(ret, f3(x+1, y, z+1) + c[z] - a[x]);
	}
	if(y < b.size() && z < c.size() && b[y] < c[z]){
		ret = max(ret, f3(x, y+1, z+1));
	}
	return d3[x][y][z] = ret;
}

int main(){
	memset(d1, -1, sizeof(d1));
	memset(d2, -1, sizeof(d2));
	memset(d3, -1, sizeof(d3));
	int n, m;
	cin >> n >> m;
	while(n--){
		string s;
		int x;
		cin >> s >> x;
		if(s == "ATK") a.push_back(x);
		else b.push_back(x);
	}
	while(m--){
		int x;
		cin >> x;
		c.push_back(x);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	cout << max({f1(0, 0), f2(0, 0, 0), f3(0, 0, 0)});
}