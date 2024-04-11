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
int N, K;
bool same[505];
vector<int> v;
int c;
int Index, val, cval;
bool IsSmall = false;
int comp;
void Query() {
    cout << "?";
    for(auto a : v) {
        cout << " " << a;
    }
    cout << endl;
    cin >> Index >> val;
    v.clear();
}

bool AllSame() {
    for(int i = 1; i <= N; i++) {
        if(i == c) continue;
        if(!same[i]) return false;
    }
    return true;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    if(K == 1) {
        cout << "! 1" << endl;
        return 0;
    }
    for(int i = 1; i <= K; i++) v.push_back(i);
    Query();
    c = Index;
    cval = val;
    comp = 1;
    if(c == comp) comp = 2;
    same[comp] = true;
    for(int i = K + 1; i <= N; i++) {
        v.push_back(i);
        for(int j = 1; j <= K; j++) {
            if(j == comp) continue;
            v.push_back(j);
        }
        Query();
        if(val > cval) IsSmall = true;
        if(val == cval) same[i] = true;
        else same[i] = false;
    }
    for(int i = 1; i <= K; i++) {
        if(i == comp or i == c) continue;
        for(int j = 1; j <= K; j++) {
            if(j == i) continue;
            v.push_back(j);
        }
        v.push_back(N);
        Query();
        if(cval == val) same[i] = same[N];
        else {
            same[i] = !same[N];
            if(val < cval and same[N]) IsSmall = true;
            if(val > cval and !same[N]) IsSmall = true;
        }
    }
    for(int i = 1; i <= K; i++) {
        if(i == c) continue;
        v.push_back(i);
    }
    v.push_back(N);
    Query();
    if(AllSame()) {
        if(val > cval) {
            cout << "! " << 1 << endl;
            return 0;
        } else {
            cout << "! " << K << endl;
            return 0;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= K; i++) {
        if(i != c and same[i]) {
            cnt++;
        }
    }
    if(IsSmall) {
        cout << "! " << cnt + 1 << endl;
    } else {
        cnt = K - 1 - cnt;
        cout << "! " << cnt + 1 << endl;
    }
    return 0;
}