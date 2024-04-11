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
ll H, W, K;
set<ll> row[100500], column[100500];
ll Up, Down, Right, Left;
ll nowh = 1;
ll noww = 1;
ll num = 1;

void debug() {
    return;
    cerr << Up << " " << Down << " " << Left << " " << Right << endl;
    cerr << nowh << " " << noww << " " << num << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W >> K;
    for(int i = 0; i < K; i++) {
        ll h, w;
        cin >> w >> h;
        column[h].insert(w);
        row[w].insert(h);
    }
    Up = 1;
    Down = H + 1;
    Left = 0;
    Right = W + 1;
    while(true) {
        /*
        */
        debug();
        ll Next = Right - 1;
        if(row[nowh].size()) {
            auto itr = row[nowh].lower_bound(noww);
            if(itr != row[nowh].end()) {
                chmin(Next, *itr - 1);
            }
        }
        if(Next <= noww && nowh != 1) break;
        num += Next - noww;
        noww = Next;
        Right = noww;
        /*
        cerr << Up << " " << Down << " " << Left << " " << Right << endl;
        cerr << nowh << " " << noww << endl;
        */
        debug();
        Next = Down - 1;
        if(column[noww].size()) {
            auto itr = column[noww].lower_bound(nowh);
            if(itr != column[noww].end()) {
                chmin(Next, *itr - 1);
            }
        }
        if(Next <= nowh) break;
        num += Next - nowh;
        nowh = Next;
        Down = nowh;
        /*
        cerr << Up << " " << Down << " " << Left << " " << Right << endl;
        cerr << nowh << " " << noww << endl;
        */
        debug();
        Next = Left + 1;
        if(row[nowh].size()) {
            auto itr = row[nowh].lower_bound(noww);
            if(itr != row[nowh].begin()) {
                itr--;
                chmax(Next, *itr + 1);
            }
        }
        if(Next >= noww) break;
        num += noww - Next;
        noww = Next;
        Left = noww;
        /*
        cerr << Up << " " << Down << " " << Left << " " << Right << endl;
        cerr << nowh << " " << noww << endl;
        */
        debug();
        Next = Up + 1;
        if(column[noww].size()) {
            auto itr = column[noww].lower_bound(nowh);
            if(itr != column[noww].begin()) {
                itr--;
                chmax(Next, *itr + 1);
            }
        }
        if(Next >= nowh) break;
        num += nowh - Next;
        nowh = Next;
        Up = nowh;
    }
    if(num == H * W - K) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}