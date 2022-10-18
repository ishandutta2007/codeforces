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

struct classcomp {
    bool operator() (pair<int, set<int>> *a, pair<int, set<int>> *b)const
    {
        if (a->second.size() < b->second.size())
            return true;
        if ((a->second.size() > b->second.size()))
            return false;
        return a->first < b->first;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;

    vector<pair<int, set<int>>> adj(n);
    FOR(i, n) adj[i].first = i;
    FOR(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].second.insert(b);
        adj[b].second.insert(a);
    }

    set<pair<int, set<int>>*, classcomp> vp;
    FOR(i, n)
    {
        vp.insert(&adj[i]);
    }

    int cnt = 0;
    while (vp.size())
    {
        //cout << "Size:" << vp.size() << endl;
        auto f = vp.begin();

        if ((*f)->second.size() == 0) {
            cnt++;
        } else {
            auto a = (*f)->first;
            auto b = *((*f)->second.begin());

            //DBG(pair<int,int>{a, b});
            if (vp.count(&adj[b])) {
                vp.erase(&adj[b]);
                adj[b].second.erase(a);
                vp.insert(&adj[b]);
            }
        }

        vp.erase(*f);

        //cout << "Size_after:" << vp.size() << endl;
    }

    /*DBG("end");
    for(auto i : adj)
    {
        for(auto t : i.second)
            cout << t << " ";
        cout << endl;
    }*/

    cout << cnt;
}