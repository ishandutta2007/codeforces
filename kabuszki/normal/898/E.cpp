#include<bits/stdc++.h>
using namespace std;

#define int long long

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,a) FOR(i,0,(a)-1)
#define SIZE(v) (int)(v).size()
#define PB push_back
#define IN insert
#define ER erase
#define ALL(a) (a).begin(),(a).end()

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VII;

PII tosquare(int a) {
    if (a == 0) return {0, 2};
    int b = sqrt(a);
    if ((b + 1) * (b + 1) <= a) b++;
    if (b * b == a) return {0, 1};
    int x = a - b * b;
    int y = (b + 1) * (b + 1) - a;
    return {min(x, y), 0};
}

void jebaj() {
    int n;
    cin >> n;
    VII v(n);
    int squares = 0, non_squares = 0;
    REP(i, n) {
        int a;
        cin >> a;
        v[i] = tosquare(a);
        if (v[i].first == 0) squares++;
        else non_squares++;
    }
    if (squares >= non_squares) {
        sort(ALL(v), [](const PII& a, const PII& b) {
             if (a.second == 0) return false;
             if (b.second == 0) return true;
             return a.second < b.second;
             });
        int res = 0;
        REP(i, n / 2 - non_squares) res += v[i].second;
        cout << res << "\n";
        return;
    }
    sort(ALL(v), [](const PII& a, const PII& b) {
         if (a.first == 0) return false;
         if (b.first == 0) return true;
         return a.first < b.first;
         });
    int res = 0;
        REP(i, n / 2 - squares) res += v[i].first;
        cout << res << "\n";
        return;
}
#undef int
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--) {
        jebaj();
    }
    return 0;
}