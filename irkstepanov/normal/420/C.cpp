#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{

    int n, p;
    vector <int> N(300500);
    vector <pair <int, int> > P(300500);
    map <pair <int, int>, int> m;

    cin >> n >> p;
    for (int i = 1; i <= n; i++)
        N[i] = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> P[i].first >> P[i].second;
        if (P[i].first > P[i].second) swap(P[i].first, P[i].second);
        m[P[i]]++;
        N[P[i].first]++;
        N[P[i].second]++;
    }

    vector <int> v;
    for (int i = 1; i <= n; i++)
        v.push_back(N[i]);

    sort (v.begin(), v.end());

    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int n1 = N[i];
        int n2 = p - n1;
        int l = 0, r = n - 1;
        while (l != r && r != l + 1)
        {
            int sr = (l + r) / 2;
            if (v[sr] >= n2) r = sr;
            else l = sr;
        }
        if (v[l] >= n2) ans += (long long) (n - l);
        else if (v[r] >= n2) ans += (long long) (n - r);
        if (n2 <= n1) ans--;
    }

    for (int i = 1; i <= n; i++)
    if (m[P[i]] != -1)
    {
        if (N[P[i].first] + N[P[i].second] - m[P[i]] < p && N[P[i].first] + N[P[i].second] >= p) ans -= 2;
        m[P[i]] = -1;
    }

    cout << ans / 2;

}