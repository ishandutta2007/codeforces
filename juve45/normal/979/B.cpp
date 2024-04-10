#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 
#define NMAX 
#define MMAX 

using namespace std;

int n, k, x[5];
string s[5];
template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int calc(string &s) {
	int f[255], ans = 0;
	memset(f, 0, sizeof(f));
	for(auto i : s)
		f[i]++;
	for(int i = 0; i < 200; i++) {
		if(! ('a' <= i && i <= 'z' || 'A' <= i && i <= 'Z')) continue;
		if(f[i] + n <= s.size())
			ans = max(ans, f[i] + n);
		else {
			int nr = f[i] + n - s.size();
			ans = max(ans, (int) s.size() - (nr == 1 && n == 1));
		}
		
	}
	return ans;
	//return min(ans + n, (int) s.size());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= 3; i++)
		cin >> s[i];

	int ans = 0;
	//Kuro, Shiro and Katie
	x[1] = calc(s[1]);
	x[2] = calc(s[2]);
	x[3] = calc(s[3]);
	// dbg_v(x, 4);
	if(x[1] > x[2] && x[1] > x[3]) cout << "Kuro";
	else if(x[2] > x[1] && x[2] > x[3]) cout << "Shiro";
	else if(x[3] > x[2] && x[3] > x[1]) cout << "Katie";
	else cout << "Draw";
}