#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back
 
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int inf = 1000000000 + 10;

int main()
{
    
    int n;
    scanf("%d", &n);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    int m;
    scanf("%d", &m);
    vector<int> b(m + 1);
    for (int j = 1; j <= m; ++j) {
        scanf("%d", &b[j]);
    }
    
    /*int n = 500;
    vector<int> a(n + 1);
    int m = 500;
    vector<int> b(m + 1);
    for (int i = 1; i <= n; ++i) {
        a[i] = b[i] = i;
    }*/
    
    int maxlen = min(n, m);
    
    vector<vector<int> > dp(m + 1, vector<int>(maxlen + 1, inf));
    vector<vector<int> > pr(n + 1, vector<int>(m + 1, inf));
    int ans_len = 0, ans_i, ans_j;
    for (int j = 0; j <= m; ++j) {
        dp[j][0] = -1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j]) {
                int lf = 0, rg = maxlen + 1;
                while (lf < rg - 1) {
                    int md = (lf + rg) >> 1;
                    if (dp[j - 1][md] < a[i]) {
                        lf = md;
                    } else {
                        rg = md;
                    }
                }
                dp[j][lf + 1] = a[i];
                for (int jj = j + 1; jj <= m; ++jj) {
                    if (dp[jj][lf + 1] > a[i]) {
                        dp[jj][lf + 1] = a[i];
                    } else {
                        break;
                    }
                }
                pr[i][j] = dp[j - 1][lf];
                if (lf + 1 > ans_len) {
                    ans_len = lf + 1;
                    ans_i = i, ans_j = j;
                }
            }
        }
        /*for (int j = 1; j <= m; ++j) {
            cout << dp[j][1] << " ";
        }
        cout << "\n";*/
    }
    
    if (ans_len == 0) {
        printf("0\n");
        return 0;
    }
    
    printf("%d\n", ans_len);
    
    int i = ans_i, j = ans_j;
    vector<int> ans;
    
    while (true) {
        ans.pb(a[i]);
        //cout << ans_i << " " << ans_j << " " << a[i] << "\n";
        int val = pr[i][j];
        if (val == -1) {
            break;
        }
        while (a[i] != val) {
            --i;
        }
        while (b[j] != val) {
            --j;
        }
    }
    
    reverse(all(ans));
    for (int k = 0; k < sz(ans); ++k) {
        printf("%d ", ans[k]);
    }
    printf("\n");

}