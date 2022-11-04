#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> a, b, c, d;
    for(int i = 0; i < n; i++) {
        int val, d1, e;
        cin >> val >> d1 >> e;
        if(d1 == 1 && e == 1) {
            a.push_back({val, i + 1});
        } else if(d1 == 1) {
            b.push_back({val, i + 1});
        } else if(e == 1) {
            c.push_back({val, i + 1});
        } else {
            d.push_back({val, i + 1});
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    int nowb = 0;
    int nowc = 0;
    int nowd = 0;
    ll ans = 2000000000000ll;
    int ansa, ansb, ansc, ansd;
    if(a.size() + b.size() < k || a.size() + c.size() < k || m < k) {
        cout << -1;
        return 0;
    }
    if(a.size() < k) {
        if(a.size() + 2 * (k - a.size()) > m) {
            cout << -1;
            return 0;
        }
    }
    ll now = 0;
    for(int i = 0; i < min((int)a.size(), m); i++) {
        now += a[i].first;
    }
    for(int i = min((int)a.size(), m); i >= 0; i--) {
        int need = m - i;
        if(k - i > (int)b.size() || k - i > (int)c.size()) {
            break;
        }
        while(nowb < k - i) {
            now += b[nowb++].first;
        }
        while(nowc < k - i) {
            now += c[nowc++].first;
        }
        int needadd = need - nowb - nowc - nowd;
        while(needadd != 0) {
            if(needadd > 0) {
                int min1 = 2000000000;
                int* minid;
                if(nowd < d.size() && d[nowd].first < min1) {
                    min1 = d[nowd].first;
                    minid = &nowd;
                }
                if(nowc < c.size() && c[nowc].first < min1) {
                    min1 = c[nowc].first;
                    minid = &nowc;
                }
                if(nowb < b.size() && b[nowb].first < min1) {
                    min1 = b[nowb].first;
                    minid = &nowb;
                }
                if(min1 == 2000000000) {
                    break;
                }
                now += min1;
                (*minid)++;
                --needadd;
            } else {
                int max1 = -2000000000;
                int* maxid;
                if(nowd > 0 && d[nowd - 1].first > max1) {
                    max1 = d[nowd - 1].first;
                    maxid = &nowd;
                }
                if(nowc > max(0, k - i) && c[nowc - 1].first > max1) {
                    max1 = c[nowc - 1].first;
                    maxid = &nowc;
                }
                if(nowb > max(0, k - i) && b[nowb - 1].first > max1) {
                    max1 = b[nowb - 1].first;
                    maxid = &nowb;
                }
                if(max1 == -2000000000) {
                    break;
                }
                now -= max1;
                (*maxid)--;
                ++needadd;
            }
        }
        if(needadd == 0 && ans > now) {
            ans = now;
            ansa = i;
            ansb = nowb;
            ansc = nowc;
            ansd = nowd;
        }
        if(i == 0) {
            break;
        }
        now -= a[i - 1].first;
    }
    cout << ans << '\n';
    for(int i = 0; i < ansa; i++) {
        cout << a[i].second << ' ';
    }
    for(int i = 0; i < ansb; i++) {
        cout << b[i].second << ' ';
    }
    for(int i = 0; i < ansc; i++) {
        cout << c[i].second << ' ';
    }
    for(int i = 0; i < ansd; i++) {
        cout << d[i].second << ' ';
    }

}