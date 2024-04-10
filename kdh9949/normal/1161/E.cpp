#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &p, int x){
	int r = (x == p[x] ? x : f(p, p[x]));
	return p[x] = r;
}

void u(vector<int> &p, int x, int y){
	y = f(p, y); x = f(p, x);
	p[y] = x;
}

queue<int> q(vector<int> v){
	cout << "Q " << (v.size() / 2);
	for(int i = 0; i < v.size(); i += 2) cout << ' ' << v[i] << ' ' << v[i + 1];
	cout << endl;

	string s; cin >> s;
	queue<int> r;
	for(char i : s) r.push(i - '0');
	return r;
}

void a(vector<int> v[]){
	cout << "A " << v[0].size() << ' ' << v[1].size() << ' ' << v[2].size() << '\n';
	for(int i = 0; i < 3; i++){
		for(int j : v[i]) cout << j << ' ';
		cout << endl;
	}
}

int mymain(){
	int n;
	cin >> n;
	if(n < 0) return 0;
	if(n == 1){
		vector<int> r[3];
		r[0].push_back(1);
		a(r);
		return 1;
	}

	vector<int> p(n + 1);
	iota(p.begin(), p.end(), 0);

	vector<int> tv;
	auto trim = [&](){ if(tv.size() & 1) tv.pop_back(); };

	for(int i = 1; i <= n; i++) tv.push_back(i); trim();
	queue<int> odd = q(tv);
	if(n == 2){
		vector<int> r[3];
		r[0].push_back(1);
		r[!odd.front()].push_back(2);
		a(r);
		return 1;
	}
	tv.clear();
	for(int i = 2; i <= n; i++) tv.push_back(i); trim();
	queue<int> eve = q(tv);
	
	for(int i = 1; i < n; i++){
		queue<int> &cur = (i & 1) ? odd : eve;
		if(cur.front()) u(p, i, i + 1);
		cur.pop();
	}
	vector<int> v;
	for(int i = 1; i <= n; i++) if(f(p, i) == i) v.push_back(i);
	
	if(v.size() >= 3){
		tv.clear();
		for(int i = 0; i < v.size(); i += 2) tv.push_back(v[i]); trim();
		for(int i = 1; i < v.size(); i += 2) tv.push_back(v[i]); trim();
		odd = q(tv);
	}
	if(v.size() >= 5){
		tv.clear();
		for(int i = 2; i < v.size(); i += 2) tv.push_back(v[i]); trim();
		for(int i = 3; i < v.size(); i += 2) tv.push_back(v[i]); trim();
		eve = q(tv);
	}

	vector<int> u(max(1, int(v.size()) - 2));
	for(int j = 0; j < 2; j++) for(int i = j; i + 2 < v.size(); i += 4){ u[i] = odd.front(); odd.pop(); }
	for(int j = 2; j < 4; j++) for(int i = j; i + 2 < v.size(); i += 4){ u[i] = eve.front(); eve.pop(); }
	vector<int> c(n + 1);
	for(int i = 0; i < v.size(); i++){
		if(i < 2) c[v[i]] = i;
		else c[v[i]] = (u[i - 2] ? c[v[i - 2]] : 3 - c[v[i - 1]] - c[v[i - 2]]);
	}
	vector<int> r[3];
	for(int i = 1; i <= n; i++) r[c[f(p, i)]].push_back(i);
	a(r);
	return 1;
}

int main(){
	int t;
	cin >> t;
	while(t--) if(!mymain()) break;
}