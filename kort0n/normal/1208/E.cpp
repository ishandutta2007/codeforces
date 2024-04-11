#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll ans[1050000];
vector<l_l> v;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, w;
    cin >> n >> w;
    while(n--) {
        ll l;
        cin >> l;
        v.resize(l);
        for(int i = 0; i < l; i++) {
            cin >> v[i].first;
            v[i].second = i + 1;
        }
        set<int> used;
        v.push_back({0, -1});
        sort(v.begin(), v.end(), greater<l_l>());
        for(int j = 0; j < v.size(); j++) {
            int pos = v[j].second;
            ll val = v[j].first;
            if(pos == -1) {
                used.insert(0);
                used.insert(l + 1);
                continue;
            }
            int Left = pos;
            int Right = w - l + pos;
            auto itr = used.lower_bound(pos);
            if(itr != used.end()) {
                //cerr << *itr << endl;
                chmin(Right, (*itr) - 1);
            }
            //if(itr == used.begin()) cerr << "begin" << endl;
            //if(itr == used.end()) cerr << "end" << endl;
            if(itr != used.begin()) itr--;
            //if(itr == used.begin()) cerr << "begin" << endl;
            //if(itr == used.end()) cerr << "end" << endl;
            if(itr != used.end() && (*itr) < pos) {
                //cerr << *itr << endl;
                chmax(Left, w - (int)l + (*itr) + 1);
            }
            chmax(Right, Left - 1);
            //cerr << j << " " << pos << " " << Left << " "<< Right << endl;
            ans[Left] += val;
            ans[Right + 1] -= val;
            used.insert(pos);
        }
    }
    for(int i = 2; i <= w; i++) ans[i] += ans[i-1];
    for(int i = 1; i <= w; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}