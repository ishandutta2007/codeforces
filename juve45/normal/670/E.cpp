#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered_set <int> s;
template<class T> ostream& print(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return print(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return print(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return print(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }

int n, k, m, p;
string op, s;

stack <char> l, r;

void del() {
	if(l.top() == '(') {
		int cnt = 1;
		l.pop();
		while(cnt) {
			cnt += (r.top() == ')' ? -1 : +1);
			r.pop();
		}
	} else {
		int cnt = 1;
		l.pop();
		while(cnt) {
			cnt += (l.top() == '(' ? -1 : +1);
			l.pop();
		}
	}

	if(!r.empty()) l.push(r.top()), r.pop();

}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> p;
	cin >> s >> op;

	for(auto i : s) l.push(i);

	while(l.size() != p) {
		r.push(l.top());
		l.pop();
	}

	for(auto x : op) {
		if(x == 'D') del();
		else if(x == 'L') {
			if(!l.empty()) r.push(l.top()), l.pop();
		} else {
			if(!r.empty()) l.push(r.top()), r.pop();
		}
	}
	string ans;

	while(!l.empty())
		ans.push_back(l.top()), l.pop();
	reverse(ans.begin(), ans.end());

	while(!r.empty())
		ans.push_back(r.top()), r.pop();
	cout << ans << '\n';
}