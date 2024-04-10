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
template <typename T, typename S>
void DBG(pair<T, S> p){if(debug)cout<<p.first<<" "<<p.second<<endl;}
template <typename T>
void DBG(vector<T> v){if(debug){for(T t:v)cout<<t<<"  ";cout<<endl;}}
template <typename T>
void DBG(T t){if(debug)cout<<t<<endl;}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n, m, k;
    cin >> n >> m >> k;

    vector<string> v(n);
    FOR(i, n) cin >> v[i];

    vector<vector<vector<pair<int, int>>>> adjacent(n, vector<vector<pair<int, int>>>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    pair<int, int> start(-1, -1);
    FOR(i, n)
    {
        FOR(j, m)
        {
            if (v[i][j] == '#')
                visited[i][j] = true;
            else
                start = make_pair(i, j);
        }
    }

    stack<pair<int, int>> s;
    if (start != make_pair(-1, -1)) {
        s.push(start);
        visited[start.first][start.second] = true;
    }

    while (s.size())
    {
        auto p = s.top();
        s.pop();

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        FOR(i, 4)
        {
            auto q = make_pair(p.first + dx[i], p.second + dy[i]);
            if (0 <= q.first && q.first < n && 0 <= q.second && q.second < m && !visited[q.first][q.second])
            {
                adjacent[p.first][p.second].push_back(q);
                adjacent[q.first][q.second].push_back(p);
                visited[q.first][q.second] = true;
                s.push(q);
            }
        }
    }

    FOR(i, n)
    {
        FOR(j, m)
        {
            if (adjacent[i][j].size() == 1)
                s.push(make_pair(i, j));
        }
    }

    while (s.size() && k)
    {
        auto p = s.top();
        s.pop();
        int i = p.first;
        int j = p.second;

        if (adjacent[i][j].size() == 1)
        {
            v[i][j] = 'X';
            auto q = adjacent[i][j][0];
            FOR(tmp, adjacent[q.first][q.second].size())
            {
                if (adjacent[q.first][q.second][tmp] == p)
                {
                    adjacent[q.first][q.second].erase(adjacent[q.first][q.second].begin() + tmp);
                    break;
                }
            }
            if (adjacent[q.first][q.second].size() == 1)
            {
                s.push(q);
            }
            k--;
        }
    }

    FOR(i, n)
    {
        cout << v[i] << endl;
    }
}