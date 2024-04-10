#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

// #define cerr if(0)cout


#define st first
#define nd second

using namespace std;

const int N = 200100;
int n, k, q, x, l, r, lg[N], rmq[15][20][N];
vector <int> v[N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << ' ';
	for(auto e : v) out << e << ' ';
	return out << '\n';
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

int m[8][5100100];

int ans[16][N];

void tr(int x, int ind) {
	for(int i = 2; i * i <= x; i++) {
		int cnt = 0;
		while(x % i == 0) {
			cnt++;
			x /= i;
		}
		if(cnt % 2 == 1)
			v[ind].push_back(i);
	}
	if(x > 1) v[ind].push_back(x);
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin >> n >> q;
	scanf("%d %d", &n, &q);
	bool ok = 0;
	for(int i = 0; i < n; i++) {
		// cin >> x;
		scanf("%d", &x);
		if(x == 4849845 && i == 0) {
			ok = 1;
		}
		tr(x, i);
	}
	memset(ans, 0x3f, sizeof ans);
	memset(m, 0x3f, sizeof m);
	// dbg_v(v, n + 1);
	for(int i = n - 1; i >= 0; i--) {
		// dbg(i);
		for(int j = 0; j < (1 << v[i].size()); j++) {
			// dbg(j);
			int tmp = 1;
			int off = v[i].size() - __builtin_popcount(j);
			for(int k = 0; k < v[i].size(); k++)
				if((1 << k) & j)
					tmp *= v[i][k];
			// dbg(tmp);
			for(int ir = 0; ir < 8; ir++)
				ans[ir + off][i] = min(ans[ir + off][i], m[ir][tmp]);

			m[off][tmp] = i;
		}
	}


	lg[1]=0;
  for (int i=2;i<=n;i++)
    lg[i]=lg[i/2]+1;
 	
 	for(int k = 0; k <= 14; k++)
	  for(int i=0; i<n; i++)
			rmq[k][0][i]=ans[k][i];
 	
 	for(int k = 0; k <= 14; k++)
	  for(int i=1;(1<<i)<=n;i++)
	    for(int j=0;j+(1<<i)-1<n;j++)
	      rmq[k][i][j]=min(rmq[k][i-1][j], rmq[k][i-1][j+(1<<(i-1))]);

	for(int i = 1; i <= q; i++) {
		scanf("%d %d", &l, &r);
		l--;
		r--;
		for(int a = 0; a <= 14; a++) {
			int lgm=lg[r-l+1];
			if(min(rmq[a][lgm][l], rmq[a][lgm][r-(1<<lgm)+1]) <= r) {
				// cout << a << '\n';
				printf("%d\n", a);
				break;
			}
		}
	}


}