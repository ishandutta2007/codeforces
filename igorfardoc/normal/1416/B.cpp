#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        int one = sum / n;
        if(sum % n != 0)
        {
            cout << "-1\n";
            continue;
        }
        vector<pair<pair<int, int>, int> > res;
        for(int i = 1; i < n; i++)
        {
            int need = (i + 1 - (a[i] % (i + 1))) % (i + 1);
            if(need != 0)
            {
                res.push_back({{0, i}, need});
            }
            a[i] += need;
            res.push_back({{i, 0}, a[i] / (i + 1)});
            a[i] = 0;
        }
        for(int i = 1; i < n; i++)
        {
            res.push_back({{0, i}, one});
        }
        cout << res.size() << '\n';
        for(int i = 0; i < res.size(); i++)
        {
            cout << res[i].first.first + 1 << ' ' << res[i].first.second + 1 << ' ' << res[i].second << '\n';
        }
    }
}