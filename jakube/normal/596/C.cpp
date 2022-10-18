#include <bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;
const long double PI = acos((long double)-1.0);

typedef long long int lint;
typedef long double ld;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;

    set<pair<int, int>> s;
    FOR(i, n)
    {
        int x, y;
        cin >> x >> y;
        s.insert(make_pair(x, y));
    }

    unordered_map<int, pair<int, int>> m;
    m.insert(make_pair(0, make_pair(0, 0)));

    vector<pair<int, int>> result;
    result.reserve(n);

    FOR(i, n)
    {
        int diff;
        cin >> diff;

        if (m.count(diff))
        {
            auto p = m[diff];
            m.erase(diff);
            result.push_back(p);

            pair<int, int> q = p;
            q.first += 1;
            if (s.count(q))
                m.insert(make_pair(q.second-q.first, q));
            pair<int, int> r = p;
            r.second += 1;
            if (s.count(r))
                m.insert(make_pair(r.second-r.first, r));
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES" << endl;
    for (auto p : result)
        cout << p.first << " " << p.second << endl;
}