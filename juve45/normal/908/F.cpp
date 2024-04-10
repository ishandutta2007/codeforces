#include <bits/stdc++.h>

#define dbg(x) //cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 
#define NMAX 
#define MMAX 

using namespace std;

long long n, k, x, mp[255], fi[4], la[4], pos;
string s;
char val;
vector <pair<long long, long long> > v;
vector <long long> p[4];

template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	mp['G'] = 1;
	mp['R'] = 2;
	mp['B'] = 3;
	fi[1] = 1e9 + 1;
	fi[2] = 1e9 + 1;
	fi[3] = 1e9 + 1;
	cin >> n;
	for(long long i = 0; i < n; i++) {
		cin >> pos >> val;
		
		p[mp[val]].push_back(i);
		fi[mp[val]] = min(fi[mp[val]], pos); 
		la[mp[val]] = pos;

		v.push_back({pos, mp[val]});	
	}

	long long ans = 0;
	if(fi[1] == 1e9 + 1) {
		if(fi[2] != 1e9 + 1) ans += la[2] - fi[2];
		if(fi[3] != 1e9 + 1) ans += la[3] - fi[3];
		cout << ans << '\n';
		return 0;
	}
	else {
		if(p[2].size() > 0 && v[*p[2].begin()].st < v[*p[1].begin()].st) ans += v[*p[1].begin()].st - v[*p[2].begin()].st;
		if(p[3].size() > 0 && v[*p[3].begin()].st < v[*p[1].begin()].st) ans += v[*p[1].begin()].st - v[*p[3].begin()].st;

		if(p[2].size() > 0 && v[*p[2].rbegin()].st > v[*p[1].rbegin()].st) ans += v[*p[2].rbegin()].st - v[*p[1].rbegin()].st;
		if(p[3].size() > 0 && v[*p[3].rbegin()].st > v[*p[1].rbegin()].st) ans += v[*p[3].rbegin()].st - v[*p[1].rbegin()].st;

	}
	dbg(ans);
	for(long long i = 1; i < p[1].size(); i++) {
		long long x = p[1][i - 1], y = p[1][i];
		vector <long long> p2, p3;
		
		for(long long j = x + 1; j < y; j++) {
			if(v[j].nd == 2) p2.push_back(v[j].st);
			if(v[j].nd == 3) p3.push_back(v[j].st);
		}

		if(p2.size() == 0 && p3.size() == 0) 
			ans += v[y].st - v[x].st;
		else if(p2.size() == 0) {
			p3.push_back(v[y].st); long long mx3 = p3[0] - v[x].st;
			for(long long i = 1; i < p3.size(); i++) mx3 = max(mx3, p3[i] - p3[i - 1]);
			ans += 2 * (v[y].st - v[x].st) - mx3;
		}
		else if(p3.size() == 0) {
			p2.push_back(v[y].st); long long mx2 = p2[0] - v[x].st;
			for(long long i = 1; i < p2.size(); i++) mx2 = max(mx2, p2[i] - p2[i - 1]);
			ans += 2 * (v[y].st - v[x].st) - mx2;
		}
		else {
			p2.push_back(v[y].st); long long mx2 = p2[0] - v[x].st;
			p3.push_back(v[y].st); long long mx3 = p3[0] - v[x].st;

			dbg(mx2);
			dbg(mx3);
			for(long long i = 1; i < p2.size(); i++) mx2 = max(mx2, p2[i] - p2[i - 1]);
			for(long long i = 1; i < p3.size(); i++) mx3 = max(mx3, p3[i] - p3[i - 1]);
			dbg(p2);
			dbg(p3);
			dbg(mx2);
			dbg(mx3);
			ans += min(2 * (v[y].st - v[x].st), 3 * (v[y].st - v[x].st) - mx2 - mx3);
		}
	}
	cout << ans << '\n';	
}