#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 1001000
#define NMAX 
#define MMAX 

using namespace std;

int n, k, f2[DMAX], f[DMAX];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	int nn = n;
	for(int i = 2;i * i <= nn; i++) {
		if(nn % i == 0) {
			f[n - i + 1]++;
			f[n + 1]--;
			while(nn % i == 0)
				nn /= i;
		}
	}
	if(nn != 1) {
		f[n - nn + 1]++;
		f[n + 1]++;
	}


	for(int i = 1; i <= n + 1; i++)
		f[i + 1] += f[i];

	// dbg_v(f, 100);

	for(int i = 1; i <= n; i++) {
		if(f[i] == 0) continue;

		int nn = i;
		for(int j = 2; j * j <= nn; j++) {
			if(nn % j == 0) {
				// dbg(f[i]);
				// dbg(j);
				f2[i - j + 1]++;
				f2[i + 1]--;
				while(nn % j == 0)
					nn /= j;
			}
		}
		// dbg(nn);
		if(nn != 1 && nn != i) {
			f2[i - nn + 1]++;
			f2[i + 1]++;
		}
	}

	// dbg_v(f2, 22);

	for(int i = 0; i < 1000000; i++) {
		if(f2[i] > 0) {
			cout << i << '\n';
			return 0;
		}
	}
}