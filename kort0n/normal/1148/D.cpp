#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
typedef pair<i_i, int> i_i_i;
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
int N;
vector<i_i_i> up, down;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        i_i a;
        cin >> a.first >> a.second;
        if(a.first > a.second) down.push_back({a, i});
        else {
            up.push_back({a, i});
        }
    }
    if(up.size() > down.size()) {
        cout << up.size() << endl;
        sort(up.begin(), up.end(), greater<i_i_i>());
        for(int i = 0; i < up.size(); i++) {
            cout << up[i].second << " ";
        }
        cout << endl;
        return 0;
    } else {
        cout << down.size() << endl;
        sort(down.begin(), down.end());
        for(int i = 0; i < down.size(); i++) {
            cout << down[i].second << " ";
        }
        cout << endl;
    }
    return 0;
}