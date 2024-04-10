#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int f[N];
map<char, int> M = {{'R', 0}, {'B', 1}, {'G', 2}};
int cnt[105];
int main(){
    bool ans = 0, wrong = 0;
    int n, m; char s[105][105];
    cin >> n >> m;
    int g[3] = {0, 0, 0};
    int cntr = 0, prev = 0;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        for(int j = 0; j < m; j++) f[i] |= (1 << M[s[i][j]]);
        if(i == 0 || f[i] != f[i - 1]){
            g[M[s[i][0]]]++;
            if(i){ cnt[cntr++] = i - prev, prev = i;}
        }
        if(__builtin_popcount(f[i]) > 1) { wrong = 1;}
    }   
    cnt[cntr++] = n - prev;
    if(!wrong && g[0] == 1 && g[1] == 1 && g[2] == 1 && cnt[0] == cnt[1] && cnt[1] == cnt[2]){
        cout << "YES"; return 0;
    }
    char _s[105][105];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) _s[i][j] = s[j][i];
    swap(n, m);
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) s[i][j] = _s[i][j], f[i] = 0;
    wrong = 0; g[0] = g[1] = g[2] = 0;
    cntr = 0, prev = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) f[i] |= (1 << M[s[i][j]]);
        if(i == 0 || f[i] != f[i - 1]){
            g[M[s[i][0]]]++;
            if(i){ cnt[cntr++] = i - prev, prev = i;}
        }
        if(__builtin_popcount(f[i]) > 1) { wrong = 1;}
    }   
    cnt[cntr++] = n - prev;
    if(!wrong && g[0] == 1 && g[1] == 1 && g[2] == 1 && cnt[0] == cnt[1] && cnt[1] == cnt[2]){
        cout << "YES"; return 0;
    }
    cout << "NO";
}