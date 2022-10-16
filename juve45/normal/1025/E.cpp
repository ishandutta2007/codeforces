#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 55;
int n, k, ord[N], lin[N], col[N], mat[N][N], mat2[N][N], x, y, target[N];
pair<int, int> pos[N], fin[N];
vector <pair<pair<int, int>, pair<int, int> > > ans;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << '\n';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << p.st << ' ' << p.nd << ' ';  
}

void move(int ind, int dx, int dy) {
	auto pp = pos[ind];
	auto pi = pp;
	mat[pp.st][pp.nd] = 0;
	pp.st += dx;
	pp.nd += dy;
	pos[ind] = pp;
	mat[pp.st][pp.nd] = ind;
	ans.push_back({pi, pp});
}

void move(int x, int y, int dx, int dy) {
	move(mat[x][y], dx, dy);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;

	for(int i = 1; i <= k; i++) {
		cin >> x >> y;
		pos[i] = {x, y};
		mat[x][y] = i;
		lin[x]++;
		col[y]++;
	}

	for(int i = 1; i <= k; i++) {
		cin >> x >> y;
		fin[i] = {x, y};
		mat2[x][y] = i;
	}


	memset(target, 0, sizeof target);
	int tg = 1;
	for(int j = 1; j <= n; j++) 
		for(int i = 1; i <= n; i++)
			if(mat[i][j])
				target[mat[i][j]] = tg++;
		
	for(int cnt = 1; cnt <= n; cnt++) {
		for(int j = 1; j <= n; j++) {
			for(int i = 1; i <= n; i++) {
				if(mat[i][j]) {
					int x= i, y = j;
					while(target[mat[x][y]] < x && mat[x - 1][y] == 0) 
						move(x, y, -1, 0), x--;
					while(target[mat[x][y]] > x && mat[x + 1][y] == 0) 
						move(x, y, 1, 0), x++;
				}
			}
		}
	}
	// for(int i = 1; i <= n; i++)
	// 	for(int j = 1; j <= n; j++)
	// 		cout << mat[i][j] << " \n"[j == n];
	// 	cout << '\n';


	// cout << ans << '\n';

	int nr_crt = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(mat2[i][j])
				ord[mat2[i][j]] = nr_crt++;

	for(int i = 1; i <= n; i++) {
		auto col_tg = ord[i];
		while(pos[i].nd < col_tg) move(i, 0, 1);
		while(pos[i].nd > col_tg) move(i, 0, -1);
	}

	// for(int i = 1; i <= n; i++)
	// 	for(int j = 1; j <= n; j++)
	// 		cout << mat[i][j] << " \n"[j == n];
	// 	cout << '\n';



	for(int i = 1; i <= n; i++) {
		auto row_tg = fin[i].st;
		while(pos[i].st < row_tg) move(i,  1, 0);
		while(pos[i].st > row_tg) move(i, -1, 0);
	}


	// for(int i = 1; i <= n; i++)
	// 	for(int j = 1; j <= n; j++)
	// 		cout << mat[i][j] << " \n"[j == n];
	// 	cout << '\n';


	for(int cnt = 1; cnt <= n; cnt++) {
		for(int j = 1; j <= n; j++) {
			for(int i = 1; i <= n; i++) {
				if(mat[i][j]) {
					int x = i, y = j;
					while(fin[mat[x][y]].nd < y && mat[x][y - 1] == 0) 
						move(x, y, 0, -1), y--;
					while(fin[mat[x][y]].nd > y && mat[x][y + 1] == 0) 
						move(x, y, 0,  1), y++;
				}
			}
		}
	}


	// for(int i = 1; i <= n; i++)
	// 	for(int j = 1; j <= n; j++)
	// 		cout << mat[i][j] << " \n"[j == n];
	// 	cout << '\n';

	cout << ans << '\n';
}