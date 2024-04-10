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

    int m, n;
    lint k;
    cin >> n >> m >> k;

    vector<vector<lint>> a(n, vector<lint>(m));
    FOR(i, n)
        FOR(j, m)
            cin >> a[i][j];

    map<pair<int, int>, int> ma;

    vector<vector<int>> visited(n, vector<int>(m, -1));

    FOR(i, n)
    {
        FOR(j, m)
        {
            if (k % a[i][j] == 0)
            {
                //dfs
                stack<pair<int, int>> s;
                s.push(make_pair(i, j));

                lint to_visit = k / a[i][j];
                lint to_v = to_visit;

                to_visit--;
                visited[i][j] = i*m + j;
                while (s.size() && to_visit)
                {
                    auto p = s.top();
                    s.pop();

                    bool brea = false;

                    for (auto pi : vector<pair<int,int>>{{0,1},{1, 0}, {-1,0}, {0,-1}})
                    {
                        pair<int,int> q(p.first + pi.first, p.second + pi.second);
                        if (0 <= q.first && 0 <= q.second && n > q.first && m > q.second)
                        {
                            //todo: optimize
                            if (a[q.first][q.second] <= a[i][j] && ma.count(q))
                            {
                                if (ma[q] < to_v)
                                {
                                    brea = true;
                                    break;
                                }
                            }



                            if (visited[q.first][q.second] != i*m + j && a[q.first][q.second] >= a[i][j])
                            {
                                visited[q.first][q.second] = i * m + j;
                                to_visit--;
                                s.push(q);
                                if (to_visit == 0)
                                {
                                    brea = true;
                                    break;
                                }
                            }
                        }
                    }

                    if (brea)
                        break;
                }

                if (to_visit == 0)
                {
                    cout << "YES" << endl;
                    FOR(c, n)
                    {
                        FOR(b, m)
                        {
                            if (visited[c][b] == i*m + j)
                                cout << a[i][j];
                            else
                                cout << 0;
                            if (b < m-1)
                                cout << " ";
                            else
                                cout << endl;
                        }
                    }

                    //cout << "YES" << a[i][j] << endl;
                    return 0;
                }
                else{
                    //cout << "NO" << a[i][j] << endl;
                    ma[make_pair(i, j)] = k / a[i][j] - to_visit;
                }
            }
        }
    }

    cout << "NO";


}