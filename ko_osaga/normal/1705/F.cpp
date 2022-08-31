#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
using word = bitset<1557>;
const int MAXL = 9;

int f[MAXL], sz[MAXL];
vector<word> queries[MAXL];

void reconstruct(int i, vector<int> &ans, vector<int> v){
	if(i == 0){
		ans[0] = v[0];
		return;
	}
	vector<int> l, r, b;
	for(int j = 0; j < (1 << (i - 1)) - 1; j++){
		l.push_back((v[2 * j + 1] + v[2 * j + 2] - v[0]) / 2);
		r.push_back((v[2 * j + 1] - v[2 * j + 2] + v[0] + 1) / 2);
		b.push_back(v[2 * j + 2] - v[0] - l.back() + r.back());
		assert(b.back() >= 0 && b.back() <= 1);
	}
	r.push_back(v[0]);
	l.push_back(v.back() - v[0] - accumulate(all(b), 0));
	vector<int> pl(f[i - 1]), pr(f[i - 1]);
	reconstruct(i - 1, pl, l);
	reconstruct(i - 1, pr, r);
	for(int i = 0; i < sz(pl); i++) ans[i] = pl[i];
	for(int i = 0; i < sz(pr); i++) ans[i + sz(pl)] = pr[i];
	for(int i = 0; i < sz(b); i++) ans[i + sz(pl) + sz(pr)] = b[i];
}

int main(){
	f[0] = 1;
	for(int i = 1; i < MAXL; i++){
		f[i] = f[i - 1] * 2 + (1 << (i - 1)) - 1;
	}
	queries[0].push_back(1);
	for(int i = 1; i < MAXL; i++){
		queries[i].push_back(0);
		for(int j = f[i - 1]; j < 2 * f[i - 1]; j++) queries[i][0][j] = 1;
		auto S = queries[i][0];
		for(int j = 0; j < sz(queries[i - 1]) - 1; j++){
			queries[i].push_back(queries[i - 1][j] | (queries[i - 1][j] << f[i - 1]));
			queries[i].push_back(queries[i - 1][j] | (S ^ (queries[i - 1][j] << f[i - 1])) | (word(1) << (2 * f[i - 1] + j)));
		}
		queries[i].push_back(0);
		for(int j = 0; j < f[i]; j++) queries[i][sz(queries[i]) - 1][j] = 1;
	}
	int n; cin >> n;
	cout << string(n, 'F') << endl;
	int x; cin >> x;
	if(x == n) return 0;
	vector<int> ret;
	for(int i = 0; i < sz(queries[8]); i++){
		string s;
		int y = x;
		for(int j = 0; j < n; j++){
			if(queries[8][i][j]) s += "T", y--;
			else s += "F";
		}
		cout << s << endl;
		int v; cin >> v; 
		if(v == n) return 0;
		v -= y;
		assert(v % 2 == 0);
		ret.push_back(v >> 1);
	}
	vector<int> ans(f[8]);
	reconstruct(8, ans, ret);
	ans.resize(n);
	for(auto &x : ans) cout << (x ? "T" : "F");
	cout << endl;
	cin >> x; assert(x == n);
}