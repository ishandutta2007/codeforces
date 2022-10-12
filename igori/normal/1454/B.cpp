#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<vector<int> > pos(n);
        for (int i = 0; i < n; i++) pos[a[i] - 1].push_back(i);
        vector<int> ok(n);
        for (int i = 0; i < n; i++) if (pos[i].size() == 1) ok[i] = 1;
        int id = -2;
        for (int i = 0; i < n; i++)
        {
            if (ok[a[i] - 1] && (id == -2 || a[id] > a[i]))
                id = i;
        }
        cout << id + 1 << "\n";
    }
}