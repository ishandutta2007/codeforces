#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

long long n, k, xt1, yt1, xt2, yt2, x[100100], y[100100];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	for(auto e : v) out << e << ' ';
	return out;
}

vector <long long> ans;

long long norm(long long x, long long y) {
	return x * x + y * y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;

	for(long long i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		
		xt1 += x[i];
		yt1 += y[i];

		xt2 -= x[i];
		yt2 -= y[i];
		if(norm(xt1, yt1) < norm(xt2, yt2)) {
			xt2 = xt1;
			yt2 = yt1;
			ans.push_back(1);
		} else  {
			xt1 = xt2;
			yt1 = yt2;
			ans.push_back(-1);
		}
	}
	
	if(norm(xt1,yt1) <= 2250000000000LL) {
		cout << ans << '\n';
		return 0;
	}


	while(true) {
		long long xt = 0, yt = 0;
		ans.clear();
		for(long long i = 1; i <= n; i++) {
			
			if(rand() % 2)
				ans.push_back(1);
			else 
				ans.push_back(-1);

			xt += ans.back() * x[i];
			yt += ans.back() * y[i];
		}

		if(norm(xt, yt) <= 2250000000000LL) {
			cout << ans << '\n';
			return 0;
		}
	}

}