#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200;

int a[2][MAXN];
int b[MAXN];
int l[2][MAXN], r[2][MAXN];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
        scanf("%d", &a[0][i]);
    for(int i = 1; i < n; i++)
        scanf("%d", &a[1][i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    for(int j = 0; j <= 1; j++){
        l[j][1] = 0;
        for(int i = 1; i < n; i++)
            l[j][i+1] = l[j][i] + a[j][i];
        r[j][n] = 0;
        for(int i = n - 1; i >= 1; i--)
            r[j][i] = r[j][i+1] + a[j][i];
    }
    for(int i = 1; i <= n; i++)
        b[i] += l[0][i] + r[1][i];
    int m1 = 10000000;
    int m2 = 10000000;
    for(int i = 1; i <= n; i++){
        if (b[i] <= m1){
            m2 = m1;
            m1 = b[i];
        }
        else{
            if (b[i] <= m2)
                m2 = b[i];
        }
    }
    printf("%d\n", m1+m2);
}