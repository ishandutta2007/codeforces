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
int H, W, Q;
string field[500];
int Exist[500][500][251];
int sum[500][500][251];
vector<i_i> Prev, Next;


int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W >> Q;
    for(int h = 0; h < H; h++) {
        cin >> field[h];
    }
    for(int h = 0; h < H - 1; h++) {
        for(int w = 0; w < W - 1; w++) {
            Prev.push_back({h, w});
        }
    }
    for(int sz = 1; sz <= 250; sz++) {
        Next.clear();
        for(auto tmp : Prev) {
            int nowh = tmp.first;
            int noww = tmp.second;
            bool ok = true;
            for(int delta = 0; delta < sz; delta++) {
                int newh = nowh - delta;
                int neww = noww - sz + 1;
                if(newh < 0 or neww < 0 or newh >= H or neww >= W or field[newh][neww] != 'R') ok = false;
            }
            for(int delta = 0; delta < sz; delta++) {
                int newh = nowh - delta;
                int neww = noww + sz;
                if(newh < 0 or neww < 0 or newh >= H or neww >= W or field[newh][neww] != 'G') ok = false;
            }
            for(int delta = 0; delta < sz; delta++) {
                int newh = nowh + delta + 1;
                int neww = noww - sz + 1;
                if(newh < 0 or neww < 0 or newh >= H or neww >= W or field[newh][neww] != 'Y') ok = false;
            }
            for(int delta = 0; delta < sz; delta++) {
                int newh = nowh + delta + 1;
                int neww = noww + sz;
                if(newh < 0 or neww < 0 or newh >= H or neww >= W or field[newh][neww] != 'B') ok = false;
            }
            for(int delta = 0; delta < sz; delta++) {
                int newh = nowh - sz + 1;
                int neww = noww - delta;
                if(newh < 0 or neww < 0 or newh >= H or neww >= W or field[newh][neww] != 'R') ok = false;
            }
            for(int delta = 0; delta < sz; delta++) {
                int newh = nowh - sz + 1;
                int neww = noww + delta + 1;
                if(newh < 0 or neww < 0 or newh >= H or neww >= W or field[newh][neww] != 'G') ok = false;
            }
            for(int delta = 0; delta < sz; delta++) {
                int newh = nowh + sz;
                int neww = noww - delta;
                if(newh < 0 or neww < 0 or newh >= H or neww >= W or field[newh][neww] != 'Y') ok = false;
            }
            for(int delta = 0; delta < sz; delta++) {
                int newh = nowh + sz;
                int neww = noww + delta + 1;
                if(newh < 0 or neww < 0 or newh >= H or neww >= W or field[newh][neww] != 'B') ok = false;
            }
            if(ok) {
                Exist[nowh][noww][sz] = true;
                Next.push_back({nowh, noww});
            }
        }
        swap(Next, Prev);
    }
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            for(int sz = 0; sz <= 250; sz++) {
                sum[h+1][w+1][sz] = sum[h][w+1][sz] + sum[h+1][w][sz] - sum[h][w][sz] + Exist[h][w][sz];
            }
        }
    }
    /*
    for(int sz = 1; sz <= 3; sz++) {
        cerr << "-" << sz << "-" << endl;
        for(int h = 0; h < H; h++) {
            for(int w = 0; w < W; w++) {
                cerr << Exist[h][w][sz] << " ";
            }
            cerr << endl;
        }
    }
    for(int sz = 1; sz <= 3; sz++) {
        cerr << "-" << sz << "-" << endl;
        for(int h = 0; h <= H; h++) {
            for(int w = 0; w <= W; w++) {
                cerr << sum[h][w][sz] << " ";
            }
            cerr << endl;
        }
    }
    */
    while(Q--) {
        int h1, w1, h2, w2;
        cin >> h1 >> w1 >> h2 >> w2;
        h1--;
        w1--;
        int ok = 0;
        int ng = 251;
        while(abs(ok - ng) > 1) {
            int mid = (ok + ng) / 2;
            int low = h1 + mid - 1;
            int up = h2 - mid;
            int lef = w1 + mid - 1;
            int ri = w2 - mid;
            if(low >= up or lef >= ri) {
                ng = mid;
                continue;
            }
            //cerr << mid << " [" << low << ", " << up << "] * [" << lef << ", " << ri << "]" << endl;
            int num = sum[up][ri][mid];
            num -= sum[low][ri][mid];
            num -= sum[up][lef][mid];
            num += sum[low][lef][mid];
            if(num >= 1) ok = mid;
            else ng = mid;
        }
        cout << ok * ok * 4 << endl;
    }
    return 0;
}