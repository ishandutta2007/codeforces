#include <bits/stdc++.h>

using namespace std;

#define int int64_t

map <string, int> kek;
map <string, bool> was;
map <pair <int, int>, int> t;
int last_kek = 0;

int get_num(string s) {
    if (was[s])
        return kek[s];
    was[s] = true;
    kek[s] = last_kek++;
    return kek[s];
}

vector <pair <pair <int, int>, int> > edges;

int32_t main()
{

    //freopen("test.in", "r", stdin);

    int n, a, b, k, f; cin >> n >> a >> b >> k >> f;
    for (int i = 0; i < n; i++) {
        string s1, s2; cin >> s1 >> s2;
        int num1 = get_num(s1);
        int num2 = get_num(s2);

        int cost = a;
        if (!edges.empty() && edges.back().first.second == num1)
            cost = b;

        t[{min(num1, num2), max(num1, num2)}] -= cost;
        edges.push_back({{num1, num2}, cost});
    }

    int res = 0;
    int r = 0;
    vector <int> y;
    for (map <pair <int, int>, int> :: iterator it = t.begin(); it != t.end(); ++it) {
        int a = (*it).first.first, b = (*it).first.second;
        int cost = -(*it).second;

        y.push_back(cost);
    }

    sort(y.begin(), y.end());
    reverse(y.begin(), y.end());

    for (int i = 0; i < (int)y.size(); i++) {
        if (i < k)
            res += min(y[i], f);
        else
            res += y[i];
    }

    cout << res << endl;

    return 0;
}