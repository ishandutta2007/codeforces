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
string S;
int P, M;
int num = 0;
int now = 0;
vector<int> children[10000];
int p[10000];
vector<int> maxi[10000], mini[10000];
bool isdigit(char a) {
    return a >= '0' and a <= '9';
}

void dfs(int now) {
    if(children[now].empty()) return;
    for(auto to : children[now]) dfs(to);
    int l = children[now][0];
    int r = children[now][1];
    int L = maxi[l].size();
    int R = mini[r].size();
    mini[now].resize(L + R, (int)1e9);
    maxi[now].resize(L + R, (int)-1e9);
    //cerr << "dfs: " << now << " " << L << " " << R << endl;
    for(int i = 0; i < L; i++) {
        for(int j = 0; j < R; j++) {
            chmax(maxi[now][i+j], maxi[l][i] + maxi[r][j]);
            chmax(maxi[now][i+j+1], maxi[l][i] - mini[r][j]);
            chmin(mini[now][i+j], mini[l][i] + mini[r][j]);
            chmin(mini[now][i+j+1], mini[l][i] - maxi[r][j]);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> S;
    cin >> P >> M;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == '(') {
            num++;
            children[now].push_back(num);
            p[num] = now;
            now = num;
        } else if(isdigit(S[i])) {
            num++;
            children[now].push_back(num);
            p[num] = now;
            maxi[num].push_back((int)(S[i] - '0'));
            mini[num].push_back((int)(S[i] - '0'));
        } else if(S[i] == ')') {
            now = p[now];
        }
    }
    /*
    for(int i = 1; i <= num; i++) {
        cerr << i << " " << p[i];
        for(auto c : children[i]) cerr << " " << c;
        cerr << endl;
    }
    */
    dfs(1);
    /*
    for(int i = 1; i <= num; i++) {
        cerr << "----" << i << "----" << endl;
        for(auto val : maxi[i]) {
            cerr << val << " ";
        }
        cerr << endl;
        for(auto val : mini[i]) {
            cerr << val << " ";
        }
        cerr << endl;
    }
    */
    cout << maxi[1][M] << endl;
    return 0;
}