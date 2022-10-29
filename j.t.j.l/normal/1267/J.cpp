#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 2e6 + 10;
const int MM = 1e9 + 7;


ll pw(ll p, ll q){
    ll ret = 1;
    for (; q; q >>= 1){
        if (q & 1)
            ret = ret * p % MM;
        p = p * p % MM;
    }
    return ret;
}

int a[MAXN];
vector<int> b;

void solve(int casi){
    //printf("Case #%d:", casi);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    b.clear();
    a[n + 1] = -1;
    for (int i = 2, cnt = 1; i <= n + 1; i++) {
        if (a[i] != a[i - 1]) {
            b.push_back(cnt);
            cnt = 1;
        }
        else {
            cnt++;
        }
    }
    sort(b.begin(), b.end());
    int m = b.size();
    vector<PII> c;
    c.emplace_back(b[0], 1);
    for (int i = 1; i < m; i++) {
        if (b[i] == b[i - 1]) c.back().second++;
        else {
            c.emplace_back(b[i], 1);
        }
    }
    // for (auto &x : c) cout << x.first << ' ' << x.second << endl;
    int ans = 1e9;
    for (int i = c[0].first + 1; i >= 2; i--) {
        int cnt = 0, flag = 1;
        for (auto &x : c) {
            int cc = (x.first - 1) / i + 1;
            if (cc * (i - 1) <= x.first && cc * i >= x.first) {
                cnt += cc * x.second;
            }
            else {
                flag = 0;
                break;
            }
        }
        if (flag) {
            ans = min(ans, cnt);
            break;
        }
    }
    printf("%d\n", ans);
}

int main(){
    int T = 1;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}