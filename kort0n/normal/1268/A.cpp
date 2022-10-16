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
string S;
string ans;

string f(string S) {
    string ans;
    for(int i = 0; i < N; i++) {
        if(i < K) {
            ans.push_back(S[i]);
        } else {
            ans.push_back(S[i % K]);
        }
    }
    return ans;
}

bool comp(string S, string T) {
    for(int i = 0; i < S.size(); i++) {
        if(S[i] != T[i]) return S[i] > T[i];
    }
    return false;
}

void add(string &S, int index) {
    if(S[index] == '9') {
        S[index] = '0';
        add(S, index - 1);
    } else {
        S[index]++;
    }
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    cin >> S;
    ans = f(S);
    if(comp(S, ans)) {
        add(ans, K - 1);
        ans = f(ans);
    }
    cout << ans.size() << endl;
    cout << ans << endl;
    return 0;
}