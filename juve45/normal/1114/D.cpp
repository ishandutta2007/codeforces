#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

template<class T> ostream& print(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return print(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return print(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return print(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }

const int N = 5005;
int n, k, m, a[N], dp[N][N];

// long double getWinProbability(long double ra, long double rb) {
//     return 1.0 / (1.0 + pow((long double) 10.0, (rb - ra) / 400.0));
// }

// long double aggregateRatings(vector<long double> teamRatings)
// {
//     long double left = 1;
//     long double right = 1E4;

//     for (int tt = 0; tt < 100; tt++) {
//         long double r = (left + right) / 2.0;

//         long double rWinsProbability = 1.0;
//         for(int i = 0;i < teamRatings.size(); i++)
//             rWinsProbability *= getWinProbability(r, teamRatings[i]);

//         long double rating = log10(1 / (rWinsProbability) - 1) * 400 + r;

//         if (rating > r)
//             left = r;
//         else
//             right = r;
//     }

//     return (left + right) / 2.0;
// }


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	int nrc = 0;
	for(int i = 1; i <= n; i++)
		cin >> a[i];

    int nn = unique (a + 1, a + n + 1) - a;
    n = nn - 1;
    dbg(n);
    dbg_v(a, n + 1);

    memset(dp, 0x3f, sizeof dp);

    for(int i = 1; i <= n; i++)
        dp[i][i] = 0;

	for(int i = 2; i <= n; i++) {
        for(int j = 1; j + i - 1 <= n; j++) {
            dp[j][j + i - 1] = min(dp[j + 1][j + i - 1] + 1, dp[j][j + i - 2] + 1);
            if(a[j] == a[j + i - 1]) {
                dp[j][j + i - 1] = min(dp[j][j + i - 1], dp[j + 1][j + i - 2] + 1);
            }
        }
		
    }
    // cout << dp[2][6] << '\n';
    // cout << dp[3][5] << '\n';
    cout << dp[1][n] << '\n';
			

	// cout << aggregateRatings({2500, 2400, 2350});

}