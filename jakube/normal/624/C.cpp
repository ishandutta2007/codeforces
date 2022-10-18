#include <bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;
const long double PI = acos((long double)-1.0);
const long long int MOD = 1e9 + 7;

typedef long long int lint;
typedef long double ld;
lint powmod(lint a,lint b, lint mod) {lint res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

const int debug = 1;
template <typename T>
void DBG(vector<T> v){if(debug){for(T t:v)cout<<t<<"  ";cout<<endl;}}
template <typename T>
void DBG(T t){if(debug)cout<<t<<endl;}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> v(m);

    FOR(i, m) {
        cin >> v[i].first >> v[i].second;
        v[i].first--;
        v[i].second--;
    }



    vector<vector<int>> adjacent(n);
    for (auto const p : v)
    {
        adjacent[p.first].push_back(p.second);
        adjacent[p.second].push_back(p.first);
    }

    set<int> a, b, c;
    vector<bool> visited(n, false);

    FOR(i, n)
    {
        if (adjacent[i].size() == n-1)
        {
            visited[i] = true;
            b.insert(i);
        }
    }

    stack<int> s;

    int a_start = -1;
    FOR(i, n)
    {
        if (!visited[i])
            a_start = i;
    }

    if (a_start >= 0) {
        s.push(a_start);
        visited[a_start] = true;

        while (s.size()) {
            auto cur = s.top();
            s.pop();
            a.insert(cur);

            for (auto next : adjacent[cur]) {
                if (!visited[next]) {
                    visited[next] = true;
                    s.push(next);
                }
            }
        }
    }

    int c_start = -1;
    FOR(i, n)
    {
        if (!visited[i])
            c_start = i;
    }

    if (c_start >= 0) {
        s.push(c_start);
        visited[c_start] = true;

        while (s.size()) {
            auto cur = s.top();
            s.pop();
            c.insert(cur);

            for (auto next : adjacent[cur]) {
                if (!visited[next]) {
                    visited[next] = true;
                    s.push(next);
                }
            }
        }
    }

    //create string
    string str = "";
    FORR(i, 0, n)
    {
        if (a.count(i))
            str += "a";
        else if (b.count(i))
            str += "b";
        else if (c.count(i))
            str += "c";
        else
        {
            cout << "No";
            return 0;
        }
    }

    FOR(i, v.size())
    {
        auto p = v[i];
        if (p.first > p.second)
        {
            v[i] = make_pair(p.second, p.first);
        }
    }

    vector<pair<int, int>> v2;
    FOR(i, n)
        FORR(j, i+1, n)
        {
            if (abs(str[i] - str[j]) <= 1)
            {
                v2.push_back(make_pair(i, j));
            }
        }



    sort(ALL(v));
    

    if (v.size() != v2.size())
    {
        cout << "No";
        return 0;
    }

    FOR(i, v.size())
    {
        if (v[i].first != v2[i].first || v[i].second != v2[i].second)
        {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes" << endl << str;
}