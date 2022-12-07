
//Karol Kaszuba

#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef double D;
typedef long double LD;
typedef vector<PII> VII;
typedef unordered_set<int> USI;
typedef unordered_set<LL> USLL;

#define FOR(i,x,y) for(auto i=(x);i<=(y);++i)
#define REP(i,x) FOR(i,0,(x)-1)
#define FORD(i,x,y) for(auto i=(x);i>=(y);--i)
#define VAR(i,c) __typeof(c) i=(c)
#define FORE(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define SIZE(c) (int)((c).size())
#define ALL(c) (c).begin(),(c).end()
#define PB push_back
#define EB emplace_back
#define IN insert
#define ER erase
#define MP make_pair
#define ST first
#define ND second
#define IOSYNC ios_base::sync_with_stdio(0)
#define FREOPEN(f) freopen(f, "r", stdin),freopen(f, "w", stdout)

VI get_bla(string s) {
	VI v(26);
	for (auto c : s) v[c - 'a']++;
	return v;
}

void reverse(string& s, int pocz, int len) {
	REP(i, len/2) {
		swap(s[pocz + i], s[pocz + len - 1 - i]);
	}
}

void jebaj() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	VI v = get_bla(s), w = get_bla(t);
	if (v != w) {
		cout << "NO\n";
		return;
	}
	if (*max_element(ALL(v)) > 1) {
		cout << "YES\n";
		return;
	}
	if (s == t) {
		cout << "YES\n";
		return;
	}
	REP(i, SIZE(s)) {
		if (s[i] != t[i]) {
			int j = std::find(ALL(s), t[i]) - s.begin();
			if (j == SIZE(s) - 1) {
				if (i == SIZE(s) - 2) {
					cout << "NO\n";
					return;
				}
				int len1 = 2, len2 = j - i;
				reverse(s, i + 1, len2);
				reverse(s, i, len1);
				reverse(t, i + 1, len1);
				reverse(t, i + 1, len2);
			} else {
				int len = j - i + 1;
				reverse(s, i, len);
				reverse(t, i + 1, len);
			}
		}
	}
	cout << "YES\n";
	return;
}


#undef int
int main() {
	IOSYNC;
	int t;
	cin >> t;
	//t = 1;
	while(t--) jebaj();
	return 0;
}


/*
 
*/