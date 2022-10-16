#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

int n, k;
string s, t;

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

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	cin >> s;

	for(int i = 0; i < k; i++)
		t += s[i];

	int sum = 0;
	for(int i = 0; i < t.size(); i++) {
		if(t[i] == '(')
			sum++;
		else sum--;

		if(sum == t.size() - i - 1) {
			for(int j = i + 1; j < t.size(); j++)
				t[j] = ')';
			break;
		}
	}
	cout << t << '\n';
}