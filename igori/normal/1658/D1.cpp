#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)

int l, r, n;

long long P(vector<int> a)
{
    sort(a.begin(), a.end());
    long long p = 0;
    forn(i, n) p += abs(a[i] - i - l);
    return p;
}

int main()
{
    int t, b = 20;
    cin >> t;
    while (t--)
    {
        cin >> l >> r, n = r - l + 1;
        vector<int> a(n), cnt(b), CNT(b);
        forn(i, n) cin >> a[i];
        forn(i, n) forn(j, b) if (a[i] & (1 << j)) cnt[j]++;
        forn(i, n) forn(j, b) if ((i + l) & (1 << j)) CNT[j]++;
        int r = 0, u = 0;
        forn(j, b) if (cnt[j] != CNT[j]) r ^= (1 << j); else if (2 * cnt[j] == n) u ^= (1 << j);
        forn(i, n) a[i] ^= r;
        // any order of bits here?
        vector<int> q;
        int rnd = rand() % b;
        for (int j = rnd; j < b; j++) if (u & (1 << j)) q.push_back(1 << j);
        for (int j = 0; j < rnd; j++) if (u & (1 << j)) q.push_back(1 << j);
        for (auto e : q)
        {
            vector<int> A = a;
            forn(i, n) A[i] ^= e;
            if (P(A) < P(a)) a = A, r ^= e;
        }
        cout << r << "\n";
    }
}