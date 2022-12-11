#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 100500;
const int inf = 1000000000;

vector <int> tmin(2 * N, inf), tmax(2 * N, -inf);
int n, k;

int get (int l, int r)
{
    int ansmax = -inf, ansmin = inf;
    for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1)
    {
        if (l & 1) {ansmax = max(ansmax, tmax[l]); ansmin = min(ansmin, tmin[l]);}
        if (!(r & 1)) {ansmax = max(ansmax, tmax[r]); ansmin = min(ansmin, tmin[r]);}
    }
    return ansmax - ansmin;
}

bool ok (int len)
{
    for (int i = 0; i + len - 1 < n; i++)
        if (get(i, i + len - 1) <= k) return true;
    return false;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> k;

    int a[N];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        tmin[i + n] = a[i];
        tmax[i + n] = a[i];
    }

    for (int i = n - 1; i; i--)
    {
        tmin[i] = min(tmin[i * 2], tmin[i * 2 + 1]);
        tmax[i] = max(tmax[i * 2], tmax[i * 2 + 1]);
    }

    int lenl = 1, lenr = n;
    while (lenr - lenl > 1)
    {
        int len = (lenl + lenr) / 2;
        if (ok(len)) lenl = len;
        else lenr = len;
    }

    vector <pii> otv;
    int len;
    if (ok(lenr)) len = lenr;
    else len = lenl;
    cout << len << " ";
    for (int i = 0; i + len - 1 < n; i++)
        if (get(i, i + len - 1) <= k) otv.pb(mp(i, i + len - 1));
    cout << otv.size() << "\n";

    for (int i = 0; i < otv.size(); i++)
        cout << otv[i].first + 1 << " " << otv[i].second + 1 << "\n";

}