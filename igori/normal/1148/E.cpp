#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << "\n";

    int n;
    cin >> n;
    vector<pair<int, int> > a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<pair<int, int> > st;
    vector<int> x, y, z;
    for (int i = 0; i < n; i++)
    {
        while (a[i].first > b[i])
        {
            int d = a[i].first - b[i];
            if (st.size() == 0)
            {
                cout << "NO\n";
                return 0;
            }
            int id = st.back().second;
            int c = st.back().first;
            d = min(d, c);
            st[st.size() - 1].first -= d;
            a[i].first -= d;
            if (st.back().first == 0)
                st.pop_back();
            x.push_back(id);
            y.push_back(a[i].second);
            z.push_back(d);
        }
        if (a[i].first < b[i])
        {
            st.push_back({b[i] - a[i].first, a[i].second});
        }
    }
    if (st.size() != 0)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << x.size() << "\n";
    for (int i = 0; i < x.size(); i++)
        cout << x[i] + 1 << " " << y[i] + 1 << " " << z[i] << "\n";
}