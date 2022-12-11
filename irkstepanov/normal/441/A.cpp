#include <bits/stdc++.h>

#define pb push_back

using namespace std;

int main()
{

    int n, v;
    cin >> n >> v;

    vector <int> ans;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        bool ok = false;
        while (k--)
        {
            int a;
            cin >> a;
            if (a < v) ok = true;
        }
        if (ok) ans.pb(i + 1);
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

}