#include <iostream>
#include <algorithm>
using namespace std;

pair<long long, long long> p[100009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].second >> p[i].first;
    sort(p + 1, p + n + 1);
    int l = 1, r = n;
    long long s = 0, ans = 0;
    while (l <= r) {
        if (p[l].first <= s) {
            while (p[l].first <= s && l <= r) {
                ans += p[l].second;
                s += p[l].second;
                l++;
            }
            continue;
        }
        if (p[r].second <= p[l].first - s) {
            ans += p[r].second * 2;
            s += p[r].second;
            r--;
        }
        else {
            ans += (p[l].first - s) * 2;
            p[r].second -= p[l].first - s;
            s = p[l].first;
        }
    }
    cout << ans << '\n';
    return 0;
}