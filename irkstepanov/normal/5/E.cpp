#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int main()
{

    int n;
    scanf("%d", &n);

    vector <int> a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int nmax = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > a[nmax]) nmax = i;

    vector <int> h;
    for (int i = nmax; i < n; i++)
        h.pb(a[i]);
    for (int i = 0; i <= nmax; i++)
        h.pb(a[i]);

    stack <pii> s;
    ll ans = 0;

    for (int i = 1; i < (int) h.size() - 1; i++)
    {
        if (h[i] == a[nmax]) {while (!s.empty()) s.pop(); continue;}
        if (s.empty()) {s.push(mp(h[i], 1)); continue;}
        if (h[i] < s.top().first)
        {
            ++ans;
            s.push(mp(h[i], 1));
        }
        else if (h[i] == s.top().first)
        {
            pii p = s.top();
            s.pop();
            ans += (ll) p.second;
            if (!s.empty()) ++ans;
            ++p.second;
            s.push(p);
        }
        else
        {
            while (!s.empty() && s.top().first < h[i])
            {
                ans += (ll) s.top().second;
                s.pop();
            }
            if (!s.empty() && s.top().first == h[i])
            {
                pii p = s.top();
                s.pop();
                ans += (ll) p.second;
                if (!s.empty()) ++ans;
                ++p.second;
                s.push(p);
            }
            else {if (!s.empty()) ++ans; s.push(mp(h[i], 1));}
        }
    }

    ll kol = 0;
    for (int i = 0; i < (int) h.size() - 1; i++)
        if (h[i] == a[nmax]) ++kol;
    ans += kol * (kol - 1) / 2;

    if (kol == 1)
    {
        vector <bool> met(h.size(), false);
        int maxim = -1;
        for (int i = 1; i < (int) h.size() - 1; i++)
        {
            maxim = max(maxim, h[i]);
            if (h[i] >= maxim) {met[i] = true; ++ans;}
        }
        maxim = -1;
        for (int i = (int) h.size() - 2; i >= 1; i--)
        {
            maxim = max(maxim, h[i]);
            if (h[i] >= maxim && !met[i]) {met[i] = true; ++ans;}
        }
    }

    else
    {
        for (int i = 0; i < h.size(); i++)
            if (h[i] == a[nmax])
        {
            if (i) //go left
            {
                int maxim = -1;
                int pos = i - 1;
                while (h[pos] != a[nmax])
                {
                    maxim = max(maxim, h[pos]);
                    if (h[pos] >= maxim) ++ans;
                    --pos;
                }
            }
            if (i != (int) h.size() - 1) //go right
            {
                int maxim = -1;
                int pos = i + 1;
                while (h[pos] != a[nmax])
                {
                    maxim = max(maxim, h[pos]);
                    if (h[pos] >= maxim) ++ans;
                    ++pos;
                }
            }
        }
    }

    cout << ans << "\n";

}