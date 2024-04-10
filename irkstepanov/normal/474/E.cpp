#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 100500;
int n;

vector <pii> t(2 * N);

pii get (int l, int r)
{
    pii ans = mp(0, -1);
    for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1)
    {
        if (l & 1 && t[l].first > ans.first) ans = t[l];
        if (!(r & 1) && t[r].first > ans.first) ans = t[r];
    }
    return ans;
}

void upd (int pos, int v)
{
    pos += n;
    t[pos] = mp(v, pos - n);
    for (pos >>= 1; pos; pos >>= 1)
    {
        if (t[pos * 2].first > t[pos * 2 + 1].first) t[pos] = t[pos * 2];
        else t[pos] = t[pos * 2 + 1];
    }
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int m;
    cin >> m;

    ll d;
    cin >> d;
    vector <ll> h(m);

    vector <ll> sorted;

    for (int i = 0; i < m; i++)
    {
        cin >> h[i];
        sorted.pb(h[i]);
    }

    sort(sorted.begin(), sorted.end());
    sorted.resize(unique(sorted.begin(), sorted.end()) - sorted.begin());
    n = sorted.size();

    map <int, int> mapa;
    vector <int> pred(m);

    for (int i = 0; i < m; i++)
    {
        int pos = lower_bound(sorted.begin(), sorted.end(), h[i]) - sorted.begin();
        int l = lower_bound(sorted.begin(), sorted.end(), h[i] - d) - sorted.begin();
        if (sorted[l] > h[i] - d) --l;
        pii p1 = get(0, l);
        int r = lower_bound(sorted.begin(), sorted.end(), h[i] + d) - sorted.begin();
        pii p2 = get(r, n - 1);
        ++p1.first, ++p2.first;
        //if (i == 3) cout << "!!" << l << " " << r << "\n";
        bool ok = false;
        if (p1.first > t[pos + n].first) {upd(pos, p1.first); pred[i] = mapa[p1.second]; ok = true;}
        if (p2.first > t[pos + n].first) {upd(pos, p2.first); pred[i] = mapa[p2.second]; ok = true;}
        if (t[pos + n].first <= 1) {upd(pos, 1); pred[i] = -1; ok = true;}
        //cout << t[pos + n].first << " " << t[pos + n].second << "\n";
        if (ok) mapa[pos] = i;
    }

    int last = 0;
    for (int i = 1; i < m; i++)
        if (t[i + n].first >= t[last + n].first) last = i;

    last = mapa[last];

    vector <int> ans;
    ans.pb(last);

    while (1)
    {
        last = pred[last];
        if (last == -1) break;
        ans.pb(last);
    }

    cout << ans.size() << "\n";
    for (int i = (int) ans.size() - 1; i >= 0; i--)
        cout << ans[i] + 1 << " ";

}