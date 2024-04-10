#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>
#include<functional>




using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const ll N = 1001;
//const int M = 10000000;



void solve() {
    int n;
    cin >> n;
    vector<vector<int> > moves(2 * n - 1, vector<int>(2 * n - 1, 1));
    vector<string> desk(n);
    for (int i = 0; i < n; ++i) {
        cin >> desk[i];
    }
    vector<pii> fig, no, yes;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (desk[i][j] == 'o')
                fig.push_back(pii(i, j));
            if (desk[i][j] == 'x')
                yes.push_back(pii(i, j));
            if (desk[i][j] == '.')
                no.push_back(pii(i, j));
        }
    for (int i = 0; i < no.size(); ++i) {
        for (int j = 0; j < fig.size(); ++j) {
            int dx = no[i].first - fig[j].first, dy = no[i].second - fig[j].second;
            moves[dx + n - 1][dy + n - 1] = 0;
        }
    }
    vector<vector<int> > beat(n, vector<int>(n, 0));
    for (int i = 0; i < fig.size(); ++i) {
        int x = fig[i].first, y = fig[i].second;
        for (int dx = -x; dx < n - x; ++dx) {
            for (int dy = -y; dy < n - y; ++dy) {
                //cerr << x << " " << dx << " " << y << " " << dy << "\n";
                if (moves[dx + n - 1][dy + n - 1])
                    beat[x + dx][y + dy] = 1;
                //cerr << x << " " << dx << " " << y << " " << dy << "\n";

            }
        }
    }
    bool ok = true;
    for (int i = 0; i < yes.size(); ++i) {
        ok = ok && beat[yes[i].first][yes[i].second];
    }
    if (!ok) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        for (int i = 0; i < moves.size(); ++i) {
            for (int j = 0; j < moves[i].size(); ++j) {
                if ((i == n - 1) && (j == n - 1))
                    cout << "o";
                else {
                    if (moves[i][j])
                        cout << "x";
                    else
                        cout << ".";
                }
            }
            cout << "\n";
        }
    }
    
}



//#define LOCAL

int main() {
	//ios_base::sync_with_stdio(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	solve();


#ifdef LOCAL
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
	return 0;
}