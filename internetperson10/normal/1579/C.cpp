#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<vector<int>> v;

void nice(int i, int j, int k) {
    k++;
    int g = 0;
    int mm = 69;
    int ii = i, jj = j;
    while(0 <= ii && ii < v.size() && 0 <= jj && jj < v[0].size()) {
        if(!v[ii][jj]) break;
        ii--;
        jj--;
        g++;
    }
    if(g < k) return;
    mm = min(mm, g);
    g = 0;
    ii = i; jj = j;
    while(0 <= ii && ii < v.size() && 0 <= jj && jj < v[0].size()) {
        if(!v[ii][jj]) break;
        ii--;
        jj++;
        g++;
    }
    if(g < k) return;
    mm = min(mm, g);
    int m = mm;
    ii = i; jj = j;
    while(0 <= ii && ii < v.size() && 0 <= jj && jj < v[0].size() && m) {
        if(!v[ii][jj]) break;
        v[ii][jj]++;
        ii--;
        jj--;
        m--;
    }
    m = mm;
    ii = i; jj = j;
    while(0 <= ii && ii < v.size() && 0 <= jj && jj < v[0].size() && m) {
        if(!v[ii][jj]) break;
        v[ii][jj]++;
        ii--;
        jj++;
        m--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int r, c, k;
        cin >> r >> c >> k;
        v.resize(r);
        for(int i = 0; i < r; i++) {
            string s;
            cin >> s;
            for(int j = 0; j < c; j++) {
                v[i].push_back(s.at(j) == '*');
            }
        }
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                nice(i, j, k);
            }
        }
        bool sad = false;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(v[i][j] == 1) sad = true;
            }
        }
        cout << (sad ? "NO\n" : "YES\n");
        vector<vector<int>>().swap(v);
    }
}