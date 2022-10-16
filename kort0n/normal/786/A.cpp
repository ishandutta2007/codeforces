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
int dp[2][8000];
int num[2][8000];
vector<ll> s[2];
ll k[2];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for(int i = 0; i < 2; i++) {
        cin >> k[i];
        for(int j = 0; j < k[i]; j++) {
            ll a;
            cin >> a;
            s[i].push_back(a);
        }
    }
    queue<i_i> que;
    dp[0][0] = -1;
    dp[1][0] = -1;
    que.push({0, 0});
    que.push({1, 0});
    while(!que.empty()) {
        auto from = que.front();
        que.pop();
        int person = from.first;
        int pos = from.second;
        for(auto delta : s[1-person]) {
            int nowperson = 1 - person;
            int nowpos = (pos + N - delta) % N;
            //cerr << person << " " << pos << " " << nowperson << " " << nowpos << endl;
            if(dp[nowperson][nowpos] != 0) continue;
            if(dp[person][pos] == -1) {
                dp[nowperson][nowpos] = 1;
                que.push({nowperson, nowpos});
            } else {
                num[nowperson][nowpos]++;
                if(num[nowperson][nowpos] == k[nowperson]) {
                    dp[nowperson][nowpos] = -1;
                    que.push({nowperson, nowpos});
                }
            }
        }
    }
    for(int i = 0; i < 2; i++) {
        for(int j = 1; j < N; j++) {
            if(j != 1) cout << " ";
            if(dp[i][j] == 1) cout << "Win";
            if(dp[i][j] == 0) cout << "Loop";
            if(dp[i][j] == -1) cout << "Lose";
        }
        cout << endl;
    }
    return 0;
}