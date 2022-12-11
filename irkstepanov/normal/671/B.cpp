#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pii;

map<ll, int> m;

void trans(pii p, ll ops, int add)
{
    m.erase(p.first);
    ll sz = (ll)p.second;
    if (ops % sz == 0) {
        p.first += (ll)(add) * ops / sz;
        m[p.first] += p.second;
    } else {
        ll all = ops / sz;
        p.first += (ll)(add) * all;
        ll rest = ops - all * sz;
        m[p.first] += (sz - rest);
        m[p.first + add] += rest;
    }
}

pll tr(pii p, ll ops, int add)
{
    ll sz = (ll)p.second;
    if (ops % sz == 0) {
        p.first += (ll)(add) * ops / sz;
        return mp(p.first, p.first);
    } else {
        ll all = ops / sz;
        p.first += (ll)(add) * all;
        return mp(min(p.first + add, p.first), max(p.first + add, p.first));
    }
}

const int buben = 31000;

void out()
{
    map<ll, int>::iterator it = m.begin();
    ll a = it->first;
    it = m.end();
    --it;
    ll b = it->first;
    cout << b - a << "\n";
}

void doop()
{
    map<ll, int>::iterator it = m.end();
    --it;
    ll b = it->first;
    --m[b];
    ++m[b - 1];
    if (m[b] == 0) {
        m.erase(it);
    }
    it = m.begin();
    ll a = it->first;
    --m[a];
    ++m[a + 1];
    if (m[a] == 0) {
        m.erase(it);
    }
}

bool almost_eq()
{
    map<ll, int>::iterator it = m.begin();
    ll a = it->first;
    it = m.end();
    --it;
    ll b = it->first;
    return a + 1 >= b;
}

int main()
{

    int n;
    ll k;
    scanf("%d%I64d", &n, &k);
    for (int i = 0; i < n; ++i) {
        ll a;
        scanf("%I64d", &a);
        ++m[a];
    }

    if (sz(m) == 1) {
        cout << "0\n";
        return 0;
    }

    while (k && sz(m) > 2) {
        map<ll, int>::iterator itb = m.begin();
        map<ll, int>::iterator ite = m.end();
        --ite;
        pii x = mp(itb->first, itb->second);
        ++itb;
        pii z = mp(itb->first, itb->second);
        pii y = mp(ite->first, ite->second);
        --ite;
        pii t = mp(ite->first, ite->second);
        ++ite;
        ll ops1 = (z.first - x.first) * (ll)(x.second);
        ll ops2 = (y.first - t.first) * (ll)(y.second);
        if (min(ops1, ops2) <= k) {
            if (ops1 <= ops2) {
                m.erase(m.begin());
                m[z.first] += x.second;
                trans(y, ops1, -1);
                k -= ops1;
                continue;
            } else {
                m.erase(ite);
                m[t.first] += y.second;
                trans(x, ops2, 1);
                k -= ops2;
                continue;
            }
        }
        trans(x, k, 1);
        trans(y, k, -1);
        k = 0;
    }

    if (sz(m) == 1) {
        cout << "0\n";
        return 0;
    }

    if (k) {
        map<ll, int>::iterator it = m.begin();
        ll a = it->first;
        int x = it->second;
        ++it;
        ll b = it->first;
        ll y = it->second;
        int done = 0;
        while (true) {
            map<ll, int> save = m;
            pii p1 = tr(mp(a, x), (done + 1) * buben, 1);
            pii p2 = tr(mp(b, y), (done + 1) * buben, -1);
            if (p1.first >= p2.second - 1) {
                m.swap(save);
                break;
            }
            ++done;
            m.swap(save);
        }
        if (k <= done * buben) {
            trans(mp(a, x), k, 1);
            trans(mp(b, y), k, -1);
            out();
            return 0;
        }
        trans(mp(a, x), done * buben, 1);
        trans(mp(b, y), done * buben, -1);
        k -= done * buben;
        while (k) {
            doop();
            if (sz(m) == 1 || almost_eq()) {
                break;
            }
            --k;
        }
        out();
        return 0;
    } else {
        map<ll, int>::iterator it = m.begin();
        ll a = it->first;
        it = m.end();
        --it;
        ll b = it->first;
        cout << b - a << "\n";
    }

}