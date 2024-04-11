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
ll N, M;
vector<ll> l, s, c;
vector<vector<ll>> Prev, Next;
ll MaxNum;

void print(ll NextNum) {
    for(int i = 0; i <= N; i++) {
        cerr << i << ":";
        for(int j = 0; j <= NextNum; j++) {
            cerr << " " << Next[i][j];
        }
        cerr << endl;
    }
}

void subprint(ll MaxNum) {
    for(int i = 0; i <= N; i++) {
        cerr << i << ":";
        for(int j = 0; j <= MaxNum; j++) {
            cerr << " " << Prev[i][j];
        }
        cerr << endl;
    }
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    l.resize(N);
    s.resize(N);
    Prev = vector<vector<ll>>(N+1, vector<ll>(N+1));
    Next = vector<vector<ll>>(N+1, vector<ll>(N+1));
    MaxNum = 0;
    c.resize(N+M);
    for(int i = 0; i < N; i++) {
        cin >> l[i];
        l[i]--;
    }
    for(int i = 0; i < N; i++) {
        cin >> s[i];
    }
    reverse(l.begin(), l.end());
    reverse(s.begin(), s.end());
    for(int i = 0; i < N + M; i++) {
        cin >> c[i];
    }
    for(int agg = 0; agg <= N + M; agg++) {
        ll NextNum = MaxNum;
        for(int i = 0; i < N; i++) {
            if(l[i] == agg) NextNum++;
        }
        //cerr << agg << " " << MaxNum << " " << NextNum << endl;
        for(int i = 0; i <= N; i++) {
            for(int j = 0; j <= NextNum; j++) {
                Next[i][j] = -1e18;
            }
        }
        for(int j = 0; j <= MaxNum; j++) {
            chmax(Next[0][j], Prev[0][j]);
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j <= MaxNum; j++) {
                chmax(Next[i+1][j], Prev[i+1][j]);
                if(l[i] == agg) {
                    chmax(Next[i+1][j+1], Prev[i][j] - s[i]);
                }
            }
            for(int j = 0; j <= NextNum; j++) {
                chmax(Next[i+1][j], Next[i][j]);
                if(l[i] == agg and j < NextNum) {
                    chmax(Next[i+1][j+1], Next[i][j] - s[i]);
                }
            }
        }
        MaxNum = NextNum / 2;
        for(int i = 0; i <= N; i++) {
            for(int j = 0; j <= MaxNum; j++) {
                Prev[i][j] = -1e18;
            }
        }
        for(int i = 0; i <= N; i++) {
            for(int j = 0; j <= NextNum; j++) {
                chmax(Prev[i][j/2], Next[i][j] + c[agg] * j);
            }
        }
        //print(NextNum);
        //subprint(MaxNum);
    }
    ll ans = Prev[N][0];
    cout << ans << endl;
    return 0;
}