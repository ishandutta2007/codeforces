#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 100500;
const int inf = 2000000000;

int n;
vector <pii> tmin(2 * N);
vector <int> tgcd(2 * N);

int gcd (int a, int b)
{
    if (a < b) swap(a, b);
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

pii min (pii a, pii b)
{
    if (a.first < b.first) return a;
    if (b.first < a.first) return b;
    return mp(a.first, a.second + b.second);
}

void upd (int pos, int x)
{
    pos += n;
    tgcd[pos] = x;
    tmin[pos] = mp(x, 1);
    for (pos >>= 1; pos; pos >>= 1)
    {
        tmin[pos] = min(tmin[pos * 2], tmin[pos * 2 + 1]);
        tgcd[pos] = gcd(tgcd[pos * 2], tgcd[pos * 2 + 1]);
    }
}

pii getmin (int l, int r)
{
    pii ans = mp(inf, 0);
    for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1)
    {
        if (l & 1) ans = min(ans, tmin[l]);
        if (!(r & 1)) ans = min(ans, tmin[r]);
    }
    return ans;
}

int getgcd (int l, int r)
{
    int ans = 0;
    for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1)
    {
        if (l & 1) ans = gcd(ans, tgcd[l]);
        if (!(r & 1)) ans = gcd(ans, tgcd[r]);
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        upd(i, a);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        --l, --r;
        pii p = getmin(l, r);
        int otv = r - l + 1;
        if (getgcd(l, r) % p.first == 0) otv -= p.second;
        cout << otv << "\n";
    }

}