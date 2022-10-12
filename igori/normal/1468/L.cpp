#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

#define all(x) (x).begin(), (x).end()

const int N = 40000;

vector<int> primes;

ll sqrt(ll x)
{
    ll L = 0, R = 1e9 + 19;
    while (L + 1 < R)
    {
        ll M = (L + R) / 2;
        if (M * M <= x)
            L = M;
        else
            R = M;
    }
    return L;
}

ll cuber(ll x)
{
    ll L = 0, R = 1e6 + 19;
    while (L + 1 < R)
    {
        ll M = (L + R) / 2;
        if (M * M <= x)
            L = M;
        else
            R = M;
    }
    return L;
}

ll multiply(ll x, ll y, ll mod)
{
    if (y == 0) return 0;
    ll l = multiply(x, y / 2, mod);
    l = (l + l) % mod;
    if (y & 1) l = (l + x) % mod;
    return l;
}

ll binpow(ll x, ll y, ll mod)
{
    if (y == 0) return 1;
    ll l = binpow(x, y / 2, mod);
    l = multiply(l, l, mod);
    if (y & 1) l = multiply(l, x, mod);
    return l;
}

mt19937_64 rnd;

ll isprime(ll x)
{
    if (x == 1) return 0;
    for (auto e : primes)
    {
        if (e >= 500) break;
        if (x == e) return 1;
        if (x % e == 0) return 0;
    }
    ll d = x - 1, s = 0;
    while (d % 2 == 0)
        d /= 2, s++;
    for (int op = 0; op < 10; op++)
    {
        ll a = rnd() % (x - 2) + 2;
        if (__gcd(a, x) > 1) return 0;
        ll c = binpow(a, d, x);
        vector<ll> fs;
        for (int t = 0; t < s; t++)
        {
            fs.push_back(c);
            c = multiply(c, c, x);
        }
        reverse(fs.begin(), fs.end());
        for (int j = 0; j < fs.size(); j++)
        {
            if (fs[j] == x - 1) break;
            if (fs[j] != x - 1 && fs[j] != 1) return 0;
        }
    }
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<ll> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    vector<int> isp(N);
    for (int i = 2; i < N; i++)
    {
        if (!isp[i])
        {
            primes.push_back(i);
            for (int j = i; j < N; j += i)
                isp[j] = 1;
        }
    }

    vector<ll> act;
    for (int i = 0; i < n; i++)
    {
        ll y = x[i];
        for (auto p : primes)
        {
            if (y % p == 0)
            {
                while (y % p == 0)
                    y /= p;
                if (y == 1)
                    act.push_back(p);
                else
                    y = 1;
            }
        }
        if (y != 1)
        {
            ll s4 = sqrt(sqrt(y));
            ll s3 = cuber(y);
            ll s2 = sqrt(y);
            if (s4 * s4 * s4 * s4 == y)
            {
                act.push_back(s4);
            }
            else if (s3 * s3 * s3 == y)
            {
                act.push_back(s3);
            }
            else if (s2 * s2 == y)
            {
                act.push_back(s2);
            }
            else if (isprime(y))
            {
                act.push_back(y);
            }
        }
    }

    sort(all(act));
    act.resize(unique(all(act)) - act.begin());

    //for (auto e : act)
    //    cerr << e << "\n";

    map<ll, int> isok;
    for (int i = 0; i < n; i++)
    {
        vector<ll> d;
        ll y = x[i];
        for (auto e : act)
        {
            if (y % e == 0)
            {
                d.push_back(e);
                while (y % e == 0)
                    y /= e;
            }
        }
        if (y == 1 && d.size() == 1)
        {
        	isok[d[0]]++;
        }
    }
    vector<ll> act2;
    for (auto e : act)
    {
        if (isok[e] >= 2)
        {
            act2.push_back(e);
            isok[e] = 2;
        }
    }
    act = act2;

    vector<pair<vector<ll>, ll> > sets;
    vector<pair<vector<ll>, ll> > sets2;
    for (int i = 0; i < n; i++)
    {
        vector<ll> d;
        ll y = x[i];
        for (auto e : act)
        {
            if (y % e == 0)
            {
                d.push_back(e);
                while (y % e == 0)
                    y /= e;
            }
        }
        if (y == 1)
        {
            if (d.size() == 1 && isok[d[0]] > 0)
            {
                sets2.push_back({d, x[i]});
                isok[d[0]]--;
            }
            else
        	{
        	    sets.push_back({d, x[i]});
        	}
        }
    }
    sort(all(sets));
    sort(all(sets2));
    if (sets.size() + sets2.size() < k)
    {
        cout << 0;
        return 0;
    }
    if (k % 2 == 0)
    {
        for (int i = 0; i < k && i < sets2.size(); i++)
        {
            cout << sets2[i].second << " ";
        }
        for (int i = sets2.size(); i < k && i < sets2.size() + sets.size(); i++)
        {
            cout << sets[i - sets2.size()].second << " ";
        }
        return 0;
    }
    else
    {
        if (sets.size() == 0)
        {
            cout << 0;
            return 0;
        }
        if (k >= sets2.size())
        {
            for (int i = 0; i < k && i < sets2.size(); i++)
            {
                cout << sets2[i].second << " ";
            }
            for (int i = sets2.size(); i < k && i < sets2.size() + sets.size(); i++)
            {
                cout << sets[i - sets2.size()].second << " ";
            }
            return 0;
        }
        int idsm = 0;
        for (int i = 0; i < sets.size(); i++)
        {
            if (sets[i].first.size() < sets[idsm].first.size())
                idsm = i;
        }
        if (1 + 2 * sets[idsm].first.size() > k)
        {
            cout << 0;
            return 0;
        }
        k--;
        cout << sets[idsm].second << " ";
        map<ll, int> prio;
        for (auto e : sets[idsm].first)
        {
            prio[e]++;
        }
        for (int i = 0; i < sets2.size(); i++)
        {
            if (prio[sets2[i].first[0]])
            {
                cout << sets2[i].second << " ";
                k--;
            }
        }
        for (int i = 0; i < sets2.size() && k > 0; i++)
        {
            if (!prio[sets2[i].first[0]])
            {
                cout << sets2[i].second << " ";
                k--;
            }
        }
    }
}