
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))

int F[4][2];
int a[105][105];

char s[105];
int main(){
    int n;
    sd(n);
    for(int r = 0; r < 4; r++){
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++){
            scanf("%s", s);
            for(int j = 0; j < n; j++){
                a[i][j] = (s[j] == '1');
                F[r][(i + j + a[i][j]) & 1]++;
            }
        }
    }
    int ans = 1e9;
    for(int i = 0; i < 16; i++){
        int tot = 0;
        int cst = 0;
        for(int j = 0; j < 4; j++){
            tot += (i >> j & 1);
            cst += F[j][i >> j & 1];
        }
        if(tot == 2){
            ans = min(ans, cst);
            // cerr << i << " " << cst << endl;
        }
    }
    printf("%d\n", ans);
}