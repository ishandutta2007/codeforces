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

int Next[26][6];
i_i dp[200000][6];

void solve() {
    string S;
    cin >> S;
    int N = S.size();
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= 4; j++) {
            dp[i][j] = {-1e9, -1};
        }
    }
    dp[0][0] = {0, -1};
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= 4; j++) {
            if(dp[i][j].first < 0) continue;
            //cerr << i << " " << j << " " << dp[i][j].first << " " << dp[i][j].second << endl;
            chmax(dp[i+1][j], dp[i][j]);
            if(Next[S[i]-'a'][j] != -1) {
                i_i tmp = dp[i][j];
                tmp.first++;
                tmp.second = i * 5 + j;
                //cerr << "-> " << i+1 << " " << Next[S[i]-'a'][j] << " " << tmp.first << " " << tmp.second << endl;
                //cerr << "from " << dp[i+1][Next[S[i]-'a'][j]].first << " " << dp[i+1][Next[S[i]-'a'][j]].second << endl;
                chmax(dp[i+1][Next[S[i]-'a'][j]], tmp);
                //cerr << " to " << dp[i+1][Next[S[i]-'a'][j]].first << " " << dp[i+1][Next[S[i]-'a'][j]].second << endl;
            }
        }
    }
    int index = 0;
    for(int i = 1; i <= 4; i++) {
        if(dp[N][i] > dp[N][index]) index = i;
    }
    set<int> st;
    for(int i = 0; i < N; i++) {
        st.insert(i);
    }
    int now = N;
    while(true) {
        int tmp = dp[now][index].second;
        index = tmp % 5;
        now = tmp / 5;
        if(tmp < 0) break;
        st.erase(now);
        //cerr << index << " " << now << endl;
    }
    cout << st.size() << endl;
    for(auto val : st) cout << val + 1 << " ";
    cout << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    for(int j = 0; j <= 4; j++) {
        Next['o' - 'a'][j] = 1;
        Next['t'-'a'][j] = 3;
    }
    Next['n' - 'a'][1] = 2;
    Next['e'-'a'][2] = -1;
    Next['w'-'a'][3]=4;
    Next['o'-'a'][4]=-1;
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}