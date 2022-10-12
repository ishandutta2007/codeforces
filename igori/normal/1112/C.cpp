#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <time.h>

using namespace std;
typedef long long ll;
#define re return
#define pb push_back
#define fi first
#define se second
#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
const int MAXN = 500001;
const long long MOD = 1e9 + 7;
ll s;
ll n, m, k;
ll a[500001];
ll cnt[500001];
ll now[500001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll ans = 1e9;
    cin >> m >> k >> n >> s;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < s; i++)
    {
        int b;
        cin >> b;
        cnt[b]++;
    }
    long long can = m - k * n;
    int i = 0, j = -1;
    long long count_good = 0;
    for (int i = 0; i < MAXN; i++)
    {
        if (cnt[i] == now[i])
            count_good++;
    }
    int id = 0;
    while (i < m)
    {
        while (j + 1 < m && count_good != MAXN)
        {
            j++;
            now[a[j]]++;
            if (now[a[j]] == cnt[a[j]])
                count_good++;
            if (count_good == MAXN)
                break;
        }
        //cout << i << " " << j << " " << count_good << endl;
        long long len = j - i + 1;
        if (count_good == MAXN)
        {
            ll l = i, r = j;
            long long gen = l / k;
            long long c = l - gen * k;
            long long d = c + len;
            long long delete_ = d - k;
            //cout << c << " " << delete_ << endl;
            if (delete_ > can)
            {
                int caa;
            }
            else
            {
                if (delete_ < ans)
                {
                    ans = delete_;
                    id = i;
                }
            }
        }
        now[a[i]]--;
        if (now[a[i]] == cnt[a[i]] - 1)
            count_good--;
        i++;
    }
    if (ans > 1e8)
    {
        cout << -1;
        return 0;
    }
    if (ans < 0)
        ans = 0;
    cout << ans << endl;
    fill(now, now + MAXN, 0);
    for (int i = id; i < m; i++)
    {
        if (ans > 0 && cnt[a[i]] == now[a[i]])
        {
            cout << i + 1 << " ";
            ans--;
        }
        else
        {
            now[a[i]]++;
        }
    }
}