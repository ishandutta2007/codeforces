#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

char s[MAXN];
int f[2][2][3];

int main(){
    int n;
    cin>>n;
    scanf("%s", s+1);
    for(int i = 0; i <= 1; i++)
        for(int j = 0; j <= 2; j++)
            f[0][i][j] = f[1][i][j] = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int p = i & 1;
        int q = 1-p;
        if (s[i] == '1'){
            f[p][0][0] = f[q][0][0];
            f[p][0][1] = f[q][0][1];
            f[p][0][2] = f[q][0][2];
            f[p][1][0] = max(f[q][0][0]+1, f[q][1][0]);
            f[p][1][1] = max(max(f[q][0][1]+1, f[q][1][1]), f[q][1][0] + 1);
            f[p][1][2] = max(max(f[q][0][2]+1, f[q][1][2]), f[q][1][1] + 1);
        }
        else{
            f[p][1][0] = f[q][1][0];
            f[p][1][1] = f[q][1][1];
            f[p][1][2] = f[q][1][2];
            f[p][0][0] = max(f[q][1][0]+1, f[q][0][0]);
            f[p][0][1] = max(max(f[q][1][1]+1, f[q][0][1]), f[q][0][0] + 1);
            f[p][0][2] = max(max(f[q][1][2]+1, f[q][0][2]), f[q][0][1] + 1);
        }
        for(int j = 0; j <= 1; j++)
            for(int k = 0; k <= 2; k++)
                ans = max(ans, f[p][j][k]);
    }
    cout<<ans<<endl;
    return 0;
}