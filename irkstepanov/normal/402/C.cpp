#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int t, n, p, i, q, w;

    cin >> t;
    vector <pair <int, int> > ans;

    for (i = 0; i < t; i++)
    {
        cin >> n >> p;
        int nmin;
        for (nmin = 1; nmin <= n; nmin++)
            if (2 * nmin + p <= nmin * (nmin - 1) / 2) break;
        int v[30][30];
        for (q = 1; q <= n; q++)
            for (w = 1; w <= n; w++)
            v[q][w] = 0;
        int c = 0;
        while (c < 2 * nmin + p)
        {
            bool ok = true;
            for (q = 1; q < nmin; q++)
                if (ok) for (w = q + 1; w <= nmin; w++)
                if (v[q][w] == 0) {v[q][w] = 1; c++; ok = false; break;}
        }
        for (q = nmin + 1; q <= n; q++)
            v[q][1] = 1, v[q][2] = 1, v[1][q] = 1, v[2][q] = 1;
        for (q = 1; q < n; q++)
            for (w = q + 1; w <= n; w++)
            if (v[q][w] == 1) ans.push_back(make_pair(q, w));
    }

    for (i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << endl;

}