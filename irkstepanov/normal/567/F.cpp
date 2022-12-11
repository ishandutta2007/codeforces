#include <bits/stdc++.h>

#define mp std::make_pair
#define pb push_back

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

int max(int a, int b)
{
    return (a > b ? a : b);
}

int min(int a, int b)
{
    return (a < b ? a : b);
}

struct pair
{
    int l, r;
    int sign;
};

typedef long long ll;

std::vector <std::string> all[4];

void full()
{
    all[1].pb("11");
    all[2].pb("1122");
    all[2].pb("1221");
    all[2].pb("2211");
    all[3].pb("332211");
    all[3].pb("233211");
    all[3].pb("133221");
    all[3].pb("123321");
    all[3].pb("113322");
    all[3].pb("223311");
    all[3].pb("122331");
    all[3].pb("112332");
    all[3].pb("112233");
}

ll f(int n, std::vector <pair> v)
{
    if (n <= 3)
    {
        ll ans = 0;
        for (int i = 0; i < sz(all[n]); i++)
        {
            std::string s = all[n][i];
            bool ok = true;
            for (int j = 0; j < sz(v); j++)
            {
                if (v[j].sign == 0 && s[v[j].l] == s[v[j].r]) continue;
                if (v[j].sign == 1 && s[v[j].l] < s[v[j].r]) continue;
                if (v[j].sign == 2 && s[v[j].l] > s[v[j].r]) continue;
                if (v[j].sign == 10 && s[v[j].l] <= s[v[j].r]) continue;
                if (v[j].sign == 20 && s[v[j].l] >= s[v[j].r]) continue;
                ok = false;
                break;
            }
            if (ok) ++ans;
        }
        return ans;
    }
    ll ans = 0;
    int len = (n / 2) * 2;
    for (int i = 0; i + len - 1 < 2 * n; i++)
    {
        std::vector <pair> out, in;
        bool ok = true;
        for (int j = 0; j < sz(v); j++)
        {
            if (v[j].l >= i && v[j].l <= i + len - 1 && v[j].r >= i && v[j].r <= i + len - 1)
            {
                pair p;
                p.l = v[j].l - i;
                p.r = v[j].r - i;
                p.sign = v[j].sign;
                in.pb(p);
            }
            else if ((v[j].l < i || v[j].l > i + len - 1) && (v[j].r < i || v[j].r > i + len - 1))
            {
                pair p;
                if (v[j].l < i) p.l = v[j].l;
                else p.l = v[j].l - len;
                if (v[j].r < i) p.r = v[j].r;
                else p.r = v[j].r - len;
                p.sign = v[j].sign;
                out.pb(p);
            }
            else
            {
                if (v[j].l >= i && v[j].l <= i + len - 1)
                {
                    if (v[j].sign == 0 || v[j].sign == 1 || v[j].sign == 10) ok = false;
                }
                else
                {
                    if (v[j].sign == 0 || v[j].sign == 2 || v[j].sign == 20) ok = false;
                }
                if (!ok) break;
            }
        }
        if (ok)
        {
            ll f1 = f(n / 2, in);
            if (i - 1 >= 0)
            {
                for (int j = 0; j < i - 1; j++)
                    out.pb({i - 1, j, 20});
            }
            if (i + len < 2 * n)
            {
                for (int j = i + len + 1; j < 2 * n; j++)
                    out.pb({i, j - len, 20});
            }
            ll f2 = f(n - n / 2, out);
//printf("%d %I64d %I64d\n", i, f1, f2);
            ans += f1 * f2;
        }
    }
return ans;
}

int main()
{
    
    full();

    int n;
    scanf("%d", &n);
    int k;
    scanf("%d", &k);
    
    std::vector <pair> v(k);
    
    for (int i = 0; i < k; i++)
    {
        int l, r;
        char c1, c2;
        scanf("%d %c%c%d", &l, &c1, &c2, &r);
        --l, --r;
        if (c1 == '=') v[i] = {l, r, 0};
        else if (c1 == '<' && c2 == ' ') v[i] = {l, r, 1};
        else if (c1 == '>' && c2 == ' ') v[i] = {l, r, 2};
        else if (c1 == '<' && c2 == '=') v[i] = {l, r, 10};
        else v[i] = {l, r, 20};
    }
    
    printf("%I64d", f(n, v));

}