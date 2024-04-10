#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

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

const long long N = 1010;
long long n, k, m, tans, val[N];

vector <vector <long long> > p = {
	{1, 2, 3},
	{1, 2, 4},
	{1, 2, 5},
	{1, 3, 4},
	{1, 3, 5},
	{1, 4, 5},
	{2, 3, 4},
	{2, 3, 5},
	{2, 4, 5},
	{3, 4, 5}
};

void solve(long long k) {
	vector <long long> v;
	for(long long i = 0; i < 5; i++) v.push_back(k + i);

	long long sres = 0, s13, s14, s25, s35, s[6];

	vector < long long > res;
	map < vector<long long>, long long > m;

	for(auto q : p) {
		cout << "? ";
		vector <long long> qq;
		for(auto i : q) {
			cout << v[i - 1] << ' ';
			qq.push_back(v[i - 1]);
		}
		cout << endl;
		cin >> tans;

		sres += tans;
		m[qq] = tans;
		res.push_back(tans);
	}
	sort(res.begin(), res.end());

	s13 = res[0];
	s14 = res[1];
	s25 = res[8];
	s35 = res[9];
	// dbg(res);
	long long s1245 = s14 + s25;
	// dbg(s1245);
	long long s15 = (sres - 3LL * s1245 - s13 - s35) / 2;
	long long s24 = s1245 - s15;

	s[3] = (sres - 3LL * s24 - 6LL * s15) / 2;
	// dbg(sres);
	long long s12345 = s[3] + s15 + s24;

	s[1] = s13 - s[3];
	s[5] = s35 - s[3];
	s[2] = s25 - s[5];
	s[4] = s14 - s[1];
	// dbg_v(s, 6);
	long long perm[] = {1, 2, 3, 4, 5};

	do {
  	for(long long i = 0; i < 5; i++)
  		val[v[i]] = s[perm[i]];

  	long long ok = 1;
  	for(auto q : p) {
  		vector <long long> qq;
  		long long mn = 2e9, mx = 0;
			for(auto i : q) {
				qq.push_back(v[i - 1]);
				mx = max(mx, val[v[i - 1]]);
				mn = min(mn, val[v[i - 1]]);
			}
			if(m[qq] != mn + mx) ok = 0;
  	}
  	if(ok) return;

  } while ( std::next_permutation(perm, perm+5) );

  cout << "Hmmm, ceva e busit" << endl;
  exit(-1); // nu gasesc solutie
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(long long i = 1; i + 4 <= n; i += 5) {
		solve(i);
	}
	if(n % 5 != 0)
		solve(n - 4);
	
	cout << "! ";
	for(long long i = 1; i <= n; i++)
		cout << val[i] << ' ';
	cout << endl;
}