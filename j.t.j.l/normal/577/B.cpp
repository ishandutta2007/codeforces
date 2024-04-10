#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1E6 + 10;
int n,m,x,tot,flag;
int a[MAXN],f[MAXN],g[MAXN];
int v[MAXN];

int main(){
    cin>>n>>m;
    for(int i = 0; i < m; i++)
        a[i] = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d",&x);
        a[x % m]++;
    }
    tot = 0;
    for(int i = 0; i < m; i++)
        if (a[i]){
            x = 1;
            while(a[i]>=x){
                v[++tot] = x * i;
                a[i] -= x;
                x*=2;
            }
            if (a[i])
                v[++tot] = a[i] * i;
        }
    for(int i = 0; i < m; i++)
        f[i] = 0;
    flag = 0;
    for(int i = 1; i <= tot; i++){
        f[0] = 1;
        for(int j = 0; j < m; j++)
            g[j] = 0;
        for(int j = 0; j < m; j++)
            if (f[j])
                g[(j + v[i]) % m] = 1;
        f[0] = 0;
        for(int j = 0; j < m; j++)
            f[j] |= g[j];
        /*cout<<i<<endl;
        for(int j = 0; j < m; j++)
        cout<<f[j]<<' ';
        cout<<endl;*/
        if (f[0]){
            flag = 1;
            break;
        }
    }
    if (flag)
        puts("YES");
    else
        puts("NO");
}