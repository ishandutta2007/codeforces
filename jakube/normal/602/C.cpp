#include <bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;
const long double PI = acos((long double)-1.0);

typedef long long int lint;
typedef long double ld;

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*400+v.second;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;


    vector<vector<bool>> v(n, vector<bool>(n, 0));

    FOR(i, m)
    {
        int t1, t2;
        cin >> t1 >> t2;
        v[t1-1][t2-1] = 1;
        v[t2-1][t1-1] = 1;
    }

    int total_time = 0;
    FOR(i, 2)
    {
        int time = 0;

        unordered_set<int> visited;
        visited.insert(0);
        multimap<int,int> s;
        s.insert(make_pair(0, 0));

        bool found=false;
        while(!found && s.size())
        {
            auto p = *s.begin();
            s.erase(s.begin());

            for(int j = 0; j < n; j++) {
                if (v[p.second][j] == i) {
                    if (!visited.count(j)) {
                        if (j == n - 1) {
                            total_time = max(total_time,  p.first + 1);
                            found = true;
                            break;
                        }

                        visited.insert(j);
                        s.insert(make_pair(p.first + 1, j));
                    }
                }
            }
        }

        if (!found)
        {
            cout << "-1";
            return 0;
        }
    }
    cout << total_time;
}