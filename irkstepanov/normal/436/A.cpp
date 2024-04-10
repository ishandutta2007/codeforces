#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

struct candy
{
    int t, h, m;
};

int main()
{

    int n, x;
    cin >> n >> x;

    vector <candy> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i].t >> c[i].h >> c[i].m;

    int ans = 0;

    for (int k = 0; k <= 1; k++)
    {
        int step = k;
        vector <int> met(n);
        int kol = 0, h = x;
        while (1)
        {
            int mmax = -1, pos;
            for (int i = 0; i < n; i++)
                if (!met[i] && c[i].t == step && c[i].h <= h && c[i].m > mmax)
                {
                    mmax = c[i].m;
                    pos = i;
                }
            if (mmax == -1) break;
            ++kol;
            h += mmax;
            met[pos] = 1;
            step = 1 - step;
        }
        ans = max(ans, kol);
    }

    cout << ans;

}