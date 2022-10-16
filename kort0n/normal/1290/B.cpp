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

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;
int a[201000];
string S;
vector<int> v[26];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> S;
    for(int i = 0; i < S.size(); i++) {
        int a = (int)(S[i] - 'a');
        v[a].push_back(i);
    }
    for(int i = 0; i < 26; i++) {
        v[i].push_back(1e9);
    }
    int Q;
    cin >> Q;
    while(Q--) {
        int l, r;
        cin >> l >> r;
        l--;
        if(r - l == 1) {
            cout << "Yes" << endl;
            continue;
        }
        if(S[l] != S[r-1]) {
            cout << "Yes" << endl;
            continue;
        }
        int num = 0;
        for(int i = 0; i < 26; i++) {
            auto itr = lower_bound(v[i].begin(), v[i].end(), l);
            if(*itr < r) num++;
        }
        //cerr << Q << " " << num << endl;
        if(num <= 2) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}