#include <bits/stdc++.h>
#define endl "\n"
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

const long long INF = 1e18;
//const ll mod = 1000000007;
string ABC[100];
int N, K;
vector<string> ans;

int main() {
    for(int i = 0; i < 26; i++) {
        ABC[i] = "A";
        ABC[i].push_back((char)('a' + i));
        ABC[i+26] = "B";
        ABC[i+26].push_back((char)('a' + i));
    }
    cin >> N >> K;
    for(int i = 0; i < K - 1; i++) {
        ans.push_back(ABC[i]);
    }
    for(int i = K; i <= N; i++) {
        string T;
        cin >> T;
        if(T == "YES") ans.push_back(ABC[i]);
        else ans.push_back(ans[i-K]);
    }
    for(auto c : ans) cout << c << " ";
    cout << endl;
    return 0;
}