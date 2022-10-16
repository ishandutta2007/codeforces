#include <bits/stdc++.h>

#define dbg(x) //cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) //do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 1000100;
int n, k, eval[N], ch[N], a, b;

string s[N];
vector <int> v[N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int op(string o, int a, int b) {
	if(o == "AND")
		return a && b;
	if(o == "OR")
		return a || b;
	return a != b;
}

void dfs(int node) {
	for(auto i : v[node])
		dfs(i);

	if(s[node] == "IN")
		return;
	if(s[node] == "NOT")
		eval[node] = 1 - eval[v[node][0]];
	else 
		eval[node] = op(s[node], eval[v[node][0]], eval[v[node][1]]);
}

void change(int node, int val) {
	dbg(node);
	dbg(val);
	if(val == 0) {
		// ch[node] = 0;
		// for(auto i : v[node])
		// 	change(i, val);
		return;
	}

	if(s[node] == "NOT")
		change(v[node][0], val);

	if(s[node] == "IN")
		ch[node] = val;

	if(s[node] == "OR") {
		if(eval[v[node][0]] == eval[v[node][1]]) {
			if(eval[v[node][0]] == 0) {
				change(v[node][0], 1);
				change(v[node][1], 1);	
			}
		} else {
			change(v[node][0], eval[v[node][0]]);
			change(v[node][1], eval[v[node][1]]);
		}
	}


	if(s[node] == "AND") {
		if(eval[v[node][0]] == eval[v[node][1]]) {
			if(eval[v[node][0]] == 1) {
				change(v[node][0], 1);
				change(v[node][1], 1);	
			}
		} else {
			change(v[node][0], 1 - eval[v[node][0]]);
			change(v[node][1], 1 - eval[v[node][1]]);
		}
	}

	if(s[node] == "XOR") {
		change(v[node][0], 1);
		change(v[node][1], 1);	
		
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		if(s[i] == "IN") {
			cin >> eval[i];
			continue;
		}
		if(s[i] == "NOT") {
			cin >> a;
			v[i].push_back(a);
			continue;
		}

		cin >> a >> b;
		v[i].push_back(a);
		v[i].push_back(b);
	}

	dfs(1);
	dbg_v(eval, n + 1);

	change(1, 1);

	dbg_v(ch, n + 1);

	for(int i = 1; i <= n; i++)
		if(s[i] == "IN") {
			if(ch[i])
				cout << 1 - eval[1];
			else cout << eval[1];
		}
}