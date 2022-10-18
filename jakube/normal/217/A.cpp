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

vector<int> parent(100, -1);
int find(int i)
{
    return i == parent[i] ? i : find(parent[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    vector<vector<int>> rows(1000), cols(1000);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    FOR(i, n)
    {
        int a, b;
        cin >> a >> b;
        v[i] = make_pair(a-1, b-1);
    }



    FOR(i, n)
    {
        auto p = v[i];
        if (rows[p.first].size() && cols[p.second].size())
        {
            int a = find(rows[p.first][0]);
            int b = find(cols[p.second][0]);

            parent[i] = a;
            parent[b] = a;
        }
        else if (rows[p.first].size())
        {
            parent[i] = find(rows[p.first][0]);
        }
        else if (cols[p.second].size())
        {
            parent[i] = find(cols[p.second][0]);
        }
        else
        {
            parent[i] = i;
        }

        rows[p.first].push_back(i);
        cols[p.second].push_back(i);
    }

    set<int> sets;
    FOR(i, n)
    {
        parent[i] = find(i);
        sets.insert(parent[i]);
    }

    cout << sets.size() - 1;



}