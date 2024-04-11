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
ll N;
vector<string> field;
vector<vector<int>> H, W;
int dh[4] = {1, -1, 0, 0};
int dw[4] = {0, 0, 1, -1};
string direction = "UDLR";
string subdirection = "DURL";
bool VALID = true;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    field.resize(N, string(N, '.'));
    H.resize(N, vector<int>(N));
    W.resize(N, vector<int>(N));
    queue<i_i> que;
    for(int h = 0; h < N; h++) {
        for(int w = 0; w < N; w++) {
            cin >> H[h][w] >> W[h][w];
            if(H[h][w] != -1) {
                H[h][w]--;
                W[h][w]--;
            }
            if(h == H[h][w] and w == W[h][w]) {
                field[h][w] = 'X';
                que.push({h, w});
            }
        }
    }
    while(!que.empty()) {
        auto tmp = que.front();
        que.pop();
        int nowh = tmp.first;
        int noww = tmp.second;
        //cerr << nowh << " " << noww << endl;
        for(int k = 0; k < 4; k++) {
            int newh = nowh + dh[k];
            int neww = noww + dw[k];
            if(newh < 0 or newh >= N) continue;
            if(neww < 0 or neww >= N) continue;
            //cerr << nowh << " " << noww << " " << newh << " " << neww << endl;
            if(field[newh][neww] != '.') continue;
            if(H[newh][neww] == -1) continue;
            if(H[nowh][noww] == H[newh][neww] and W[nowh][noww] == W[newh][neww]) {
                field[newh][neww] = direction[k];
                que.push({newh, neww});
            }
        }
    }
    //for(int i = N; i < N; i++) cerr << field[i] << endl;
    for(int h = 0; h < N; h++) {
        for(int w = 0; w < N; w++) {
            if(field[h][w] != '.') continue;
            if(H[h][w] != -1) {
                VALID = false;
                break;
            }
            for(int k = 0; k < 4; k++) {
                int newh = h + dh[k];
                int neww = w + dw[k];
                if(newh < 0 or newh >= N) continue;
                if(neww < 0 or neww >= N) continue;
                if(H[newh][neww] == -1) {
                    field[h][w] = subdirection[k];
                }
            }
            if(field[h][w] == '.') {
                VALID = false;
            }
        }
    }
    if(!VALID) {
        cout << "INVALID" << endl;
        return 0;
    }
    cout << "VALID" << endl;
    for(int i = 0; i < N; i++) {
        cout << field[i] << endl;
    }
    return 0;
}