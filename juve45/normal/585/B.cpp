#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 105;
int n, k, pos, use[4][N];

string s[4];

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

bool valid(int h) {
	return (h >= 1 && h <= 3);
}

string solve() {
	memset(use, 0, sizeof use);
	dbg_ok;
	cin >> n >> k;
	for(int i = 1; i <= 3; i++) {
		cin >> s[i];
		s[i] += "....";
		// dbg(s[i]);
		if(s[i][0] == 's')
			pos = i;
	}

	// dbg(pos);

	queue <pair<int, int> > q;
	q.push({0, pos});

	while(!q.empty()) {
		auto pp = q.front();
		if(pp.st >= n - 1)
			return "YES";
		// dbg(pp);
		q.pop();
		if(pp.st % 3 == 0) {

			if(s[pp.nd][pp.st + 1] == '.' && !use[pp.nd][pp.st + 1])
				q.push({pp.st + 1, pp.nd}),
				use[pp.nd][pp.st + 1] = 1;

		} else if(pp.st % 3 == 1) {

			if(use[pp.nd][pp.st] == 1)
				for(int i = -1; i <= 1; i++)
					if(valid(pp.nd + i) && s[pp.nd + i][pp.st] == '.' && !use[pp.nd + i][pp.st])
						q.push({pp.st, pp.nd + i}),
						use[pp.nd + i][pp.st] = 2;

			if(s[pp.nd][pp.st + 1] == '.' && s[pp.nd][pp.st + 2] == '.' && !use[pp.nd][pp.st + 2]) {
				q.push({pp.st + 2, pp.nd}),
				use[pp.nd][pp.st + 2] = 3;
			}
		}
	}
	
	return "NO";
}

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++)
	cout << solve() << '\n';
}