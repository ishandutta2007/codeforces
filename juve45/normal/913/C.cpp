#include <bits/stdc++.h>

#define dbg(x) //cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) //do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok //cerr<<"OK!\n"

#define DMAX 
#define NMAX 
#define MMAX 

using namespace std;

long long n, k, x, l, c[33];
string s;

template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << v.size() << '\n';
	for(auto e : v)
		out << e << '\n';
	return out;
}

inline long long ind(long long l) {
	long long i = 1;
	while(true) {
		if((1LL << (i - 1)) < l) i++;
		else break;
	}
	return i;
}

inline long long mn(long long index) {
	long long mnn = c[index];
	for(int i = index; i <= 30; i++)
		mnn = min(mnn, c[i]);
	dbg(index);
	dbg(mnn);
	return mnn;
	return c[index];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> l;
//	for(long long i = 0; i <= 30; i++)
	c[0] = 1000000009;

	for(long long i = 1; i <= n; i++) {
		cin >> c[i];	
		if(c[i] > 2 * c[i - 1])
			c[i] = 2 * c[i - 1];
	}
	
	for(int i = n + 1; i <= 31; i++)
		c[i] = 2 * c[i - 1];

	 dbg_v(c, 30);
	long long ans = 1e18 + 100;
	for(long long i = 30; i > 0; i--)
		if(l <= (1 << (i - 1))) 
			ans = min(ans, (long long)c[i]);
	dbg(ans);
	long long i = 30, x = 1;
	//while(2 * x <= l) x *= 2, i++;
	long long ans2 = 0;
	while(l) {
		dbg(l);
		dbg(i);
		dbg(c[i]);
		if(l >= (1 << (i - 1))) {
			l -= (1 << (i - 1));
			ans2 += 1LL * c[i];
			ans = min(ans, ans2 + mn(ind(l)));
		}
		i--;
		dbg(ans2);
		dbg(ans);
		dbg_ok;
	}
	cout << min(ans, ans2) << '\n';
}