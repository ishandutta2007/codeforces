#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;

struct type
{
    int n, p;
};

bool comp (type a, type b)
{
    return (a.p > b.p);
}

int main()
{

    int n, v;
    cin >> n >> v;

    vector <type> b, k;
    for (int i = 1; i <= n; i++)
    {
        int t, p;
        cin >> t >> p;
        type dat;
        dat.p = p, dat.n = i;
        if (t == 1) b.pb(dat);
        else k.pb(dat);
    }

    sort (b.begin(), b.end(), comp);
    sort (k.begin(), k.end(), comp);

    vector <int> sk, sb;
    sk.pb(0);
    sb.pb(0);

    for (int i = 0; i < k.size(); i++)
        sk.pb(sk[i] + k[i].p);
    for (int i = 0; i < b.size(); i++)
        sb.pb(sb[i] + b[i].p);

    int ans = -1, posk, posb;
    for (int kk = 0; kk <= k.size(); kk++)
    {
        int kb = v - 2 * kk;
        if (kb < 0) break;
        if (kb > b.size()) kb = b.size();
        if (ans < sk[kk] + sb[kb])
        {
            ans = sk[kk] + sb[kb];
            posk = kk;
            posb = kb;
        }
    }

    cout << ans << "\n";
    vector <int> vct;
    for (int i = 0; i < posk; i++)
        vct.pb(k[i].n);
    for (int i = 0; i < posb; i++)
        vct.pb(b[i].n);
    sort(vct.begin(), vct.end());
    for (int i = 0; i < vct.size(); i++)
        cout << vct[i] << " ";

}