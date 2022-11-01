#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

const int MAX_N = 100010;
int SIZE;
int nxt[MAX_N][26];

int dfs1(int turn, int p) {
    for(int i = 0; i < 26; i++) {
        if(nxt[p][i] != -1 && dfs1(turn ^ 1, nxt[p][i]) == turn) {
            return turn;
        }
    }
    return turn ^ 1;
}

int dfs2(int turn, int p) {
    bool win = true;
    REP(i, 26) if(nxt[p][i] != -1) win = false;
    if(win) return turn;
    for(int i = 0; i < 26; i++) {
        if(nxt[p][i] != -1 && dfs2(turn ^ 1, nxt[p][i]) == turn) {
            return turn;
        }
    }
    return turn ^ 1;
}
int main(){
    int n, k;
    while(cin >> n >> k) {
        SIZE = 1;
        memset(nxt, -1, sizeof(nxt));
        REP(i, n) {
            string s;
            cin >> s;
            int p = 0;
            for(char c : s) {
                int x = c - 'a';
                if(nxt[p][x] == -1) {
                    nxt[p][x] = SIZE++;
                }
                p = nxt[p][x];
            }
        }
        string win = "First";
        string lose = "Second";
        if(dfs1(0, 0) == dfs2(0, 0)) {
            cout << (dfs1(0, 0) == 0 ? win : lose) << endl;
        } else if(dfs1(0, 0) == 1) {
            cout << lose << endl;
        } else {
            cout << (k % 2 == 1 ? win : lose) << endl;
        }
    }
    return 0;
}