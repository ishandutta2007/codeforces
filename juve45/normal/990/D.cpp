#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 1010;
int n, k, a, b;
bool m[N][N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

//cazul cu 2

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> a >> b;

	if(n == 2) {
		
		if(a == b) {
			cout << "NO\n";
		} else if(a == 1) {
			cout << "YES\n01\n10\n";
		} else 
			cout << "YES\n00\n00\n";

		return 0;
	}

	if(n == 3 && a == 1 && b == 1) {
		cout << "NO\n";
		return 0;
	}

	if(a == 1 && b != 1) {
		cout << "YES\n";
		for(int i = 0; i < n; i++)
			for(int j = 0 ;j < n; j++)
				if(i == j + 1 && j < n - b)
					m[i][j] = 1;
				else if(j == i + 1 && i < n - b)
					m[i][j] = 1;

		for(int i = 0; i < n; i++)
			for(int j = 0 ;j < n; j++)
				if(i != j)
					m[i][j] = 1 - m[i][j];
				else m[i][j] = 0;

	} else if(b == 1){
		cout << "YES\n";
		for(int i = 0; i < n; i++)
			for(int j = 0 ;j < n; j++)
				if(i == j + 1 && j < n - a)
					m[i][j] = 1;
				else if(j == i + 1 && i < n - a)
					m[i][j] = 1;
		m[0][0] = 0;
	} else {
		cout << "NO\n";
		return 0;
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cout << m[i][j];
		cout << '\n'; 
	}
}