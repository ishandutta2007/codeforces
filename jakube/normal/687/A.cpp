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
    for (int idx = 0; idx < m;  idx++)
        cin >> v[idx].first >> v[idx].second;
    
    vector<vector<int>> adj(n);
    for (auto p : v)
    {
        adj[p.first-1].push_back(p.second - 1);
        adj[p.second-1].push_back(p.first-1);
    }

    set<int> A, B;

    deque<pair<int, int>> q;
    for (int vertex = 1; vertex <= n; vertex++)
    {
        q.push_back(make_pair(vertex-1, -1));
    }

    while (q.size()) {
        auto p = q.front();
        q.pop_front();

        int vertex = p.first;
        int to = p.second;

        if (A.count(vertex) && B.count(vertex)) {
            if (to == -1)
                continue;
            cout << "-1" << endl;
            return 0;
        }

        if (to == 0) {
            if (A.count(vertex)) {
                continue;
            }
            if (B.count(vertex))
            {
                cout << "-1" << endl;
                return 0;
            }
            A.insert(vertex);

            for (int neig : adj[vertex]) {
                q.push_front(make_pair(neig, 1));
            }
        }

        else if (to == 1) {
            if (B.count(vertex)) {
                continue;
            }
            if (A.count(vertex))
            {
                cout << "-1" << endl;
                return 0;
            }
            B.insert(vertex);

            for (int neig : adj[vertex]) {
                q.push_front(make_pair(neig, 0));
            }
        }

        else {
            if (A.count(vertex) || B.count(vertex))
                continue;
            if (adj[vertex].size()) {
                A.insert(vertex);
                for (int neig : adj[vertex])
                    q.push_front({neig, 1});
            }
        }

    }

    cout << A.size() << endl;
    for (int t : A)
        cout << t+1 << " ";
    cout << endl;
    
    cout << B.size() << endl;
    for (int t : B)
        cout << t+1 << " ";
    cout << endl;
}