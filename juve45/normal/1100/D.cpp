#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

const int N = 1005;
int n, k, m, rx, ry, x[N], y[N], mat[N][N], mx, my;
int where[2][2], okk;
int d[] = {-1, 1};


void Center() {
	while(rx != 500 || ry != 500) {
		int dx = 0, dy = 0;
		if(rx != 500) dx = (500 - rx) / abs(500 - rx);
		if(ry != 500) dy = (500 - ry) / abs(500 - ry);

		if(mat[rx + dx][ry + dy] == 1) {
			cout << rx + dx << ' ' << ry << endl;
			exit(0);
		} else 
		cout << rx + dx << ' ' << ry + dy << endl;
		rx += dx;
		ry += dy;

		cin >> k >> mx >> my;
		if(k == -1) exit(0);
		mat[x[k]][y[k]] = 0;
		mat[mx][my] = 1;
		x[k] = mx;
		y[k] = my;
	}
}

void Margin() {
	for(int i = 1; i <= 666; i++)
		where[x[i] > 500][y[i] > 500]++;

	int ii = 0, jj = 0;
	if(where[1][0] < where[ii][jj]) ii = 1, jj = 0;
	if(where[1][1] < where[ii][jj]) ii = 1, jj = 1;
	if(where[0][1] < where[ii][jj]) ii = 0, jj = 1;
	ii = 1 - ii;
	jj = 1 - jj;

	for(int i = 1; i < 500; i++) {
		int dx = d[ii];
		int dy = d[jj];

		if(mat[rx + dx][ry + dy] == 1) {
			cout << rx + dx << ' ' << ry << endl;
			exit(0);
		} else 
		cout << rx + dx << ' ' << ry + dy << endl;
		rx += dx;
		ry += dy;

		cin >> k >> mx >> my;
		if(k == -1) exit(0);
		mat[x[k]][y[k]] = 0;
		mat[mx][my] = 1;
		x[k] = mx;
		y[k] = my;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> rx >> ry;
	for(int i = 1; i <= 666; i++) {
		cin >> x[i] >> y[i];
		mat[x[i]][y[i]] = 1;
	}
	Center();
	Margin();
}