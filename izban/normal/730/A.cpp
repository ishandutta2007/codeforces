/**
 *    author:  SPb ITMO University 1
 *    created: 27.10.2016 11:01:52       
**/
#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

using namespace std;

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = 1.01e9;
const dbl eps = 1e-9;

/* --- main part --- */



int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif

    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<pair<int, int> > b(n);
        for (int i = 0; i < n; i++) b[i] = make_pair(a[i], i);
        sort(b.begin(), b.end());

        //int r = a[0];
        int r = b[0].first;
        for (; r > 0; r--) {
            int sum = 0, last = 0;
            for (int i = 0; i < n - 1; i++) sum += b[i].first - r;
            last = b[n - 1].first - r;

            //if (r == a[0]) cerr << r << " " << sum << " " << last << endl;
            if (last > sum) continue;
            if ((sum + last) % 2 == 0) {
                break;
            }
            if (n < 3) continue;
            vector<pair<int, int> > c = b;
            bool fail = 0;
            for (int i = 0; i < 3; i++) {
                if (c[n - i - 1].first == r) fail = 1;
                c[n - i - 1].first--;
            }
            if (fail) continue;
            sort(c.begin(), c.end());
            sum = 0; last = 0;
            for (int i = 0; i < n - 1; i++) sum += c[i].first - r;
            last = c[n - 1].first - r;
            if (last > sum) continue;
            if ((sum + last) % 2 == 0) {
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            b[i].first -= r;
        }
        int sum = 0;
        for (int i = 0; i < n; i++) sum += b[i].first;

        vector<vector<int> > ans;
        if (sum % 2 == 1 && n >= 3) {
            vector<int> cur(n);
            for (int i = 0; i < 3; i++) {
                //assert(b[n - i - 1].first > 0);
                b[n - i - 1].first = max(0, b[n - i - 1].first - 1);
                cur[b[n - i - 1].second] = 1;
            }
            ans.push_back(cur);
        }

        while (1) {
            sort(b.begin(), b.end());
            sum = 0;
            for (int i = 0; i < n; i++) sum += b[i].first;
            //cerr << sum << endl;
            if (sum == 0) break;
            vector<int> cur(n);
            for (int i = 0; i < 2;i ++) {
                b[n - i - 1].first = max(0, b[n - i - 1].first - 1);
                cur[b[n - i - 1].second] = 1;
            }
            ans.push_back(cur);
        }

        cout << r << endl;
        cout << ans.size() << endl;
        for (int i = 0; i < (int)ans.size(); i++) {
            for (int j = 0; j < n; j++) cout << ans[i][j];
            cout << endl;
        }
    }
    
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}