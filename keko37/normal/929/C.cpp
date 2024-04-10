#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <iostream>

const int N = 1e3 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

typedef long long ll;

ll k,cur,sol = 0,ch[N][10],n1,n2,n3,a[N][10],n[4],c[4];


void precompute(){
    for(int i = 0;i<N;i++){
        ch[i][0] = 1;
        ch[i][1] = i;
        ch[i][2] = i * (i - 1) / 2;
        ch[i][3] = i * (i - 1) * (i - 2) / 6;
    }
}

int main(){
    precompute();
    scanf("%I64d%I64d%I64d",n,n+1,n+2);
    for(int i = 0;i<3;i++)
        for(int j = 0;j<n[i];j++)
            scanf("%I64d",&a[j][i]);
    for(int i = 0;i<3;i++){
        for(int j = 0;j<n[i];j++){
            memset(c,0,sizeof(c));
            for(int k = 0;k<3;k++){
                for(int m = 0;m<n[k];m++)
                    if(a[m][k] > a[j][i] && a[m][k] <= 2 * a[j][i]) c[k]++;
            }
            sol += ch[c[0]][1 - (i == 0)] * ch[c[1]][2 - (i == 1)] * ch[c[2]][3 - (i == 2)];
        }
    }
    printf("%I64d\n",sol);
}