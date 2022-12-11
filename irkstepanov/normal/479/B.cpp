#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

int main()
{

    int n, k;
    cin >> n >> k;

    int a[120];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n == 1) {cout << "0 0\n"; return 0;}

    vector <pii> ans;
    int d;
    int step = 0;

    for (; ; step++)
    {
        int minim = 100500, nmin, maxim = -100500, nmax;
        for (int i = 0; i < n; i++)
            if (a[i] < minim)
        {
            minim = a[i];
            nmin = i;
        }
        for (int i = n - 1; i >= 0; i--)
            if (a[i] > maxim)
        {
            maxim = a[i];
            nmax = i;
        }
        d = maxim - minim;
        if (step == k || !d) break;
        ans.pb(mp(nmax, nmin));
        ++a[nmin], --a[nmax];
    }

    cout << d << " " << step << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";

}

//pitri doooooooooor