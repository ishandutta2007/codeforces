#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5000;
long long v[MAXN], d[MAXN], p[MAXN];
int a[MAXN];
int vis[MAXN];

int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
        scanf("%I64d%I64d%I64d", &v[i], &d[i], &p[i]);
    for(int i = 1; i <= n; i++)
        vis[i] = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        if (!vis[i] && p[i] >= 0){
            cnt++;
            a[cnt] = i;
            v[i]++;
            for(int j = i+1; j <= n; j++)
                if (!vis[j] && p[j] >= 0){
                    v[i]--;
                    if (v[i] > 0)
                        p[j] -= v[i];
                }
        //  for(int j = 1; j <= n; j++)
        //      cout<<p[j]<<' '; cout<<endl;
            long long sum = 0;
            for(int j = i+1; j <= n; j++)
                if (!vis[j]){
                    p[j] -= sum;
                    if (p[j] < 0){
                        vis[j] = 1;
                        sum += d[j];
                    }
                }
        //  for(int j = 1; j <= n; j++)
        //      cout<<p[j]<<' '; cout<<endl<<endl;
        }
    cout<<cnt<<endl;
    for(int i = 1; i <= cnt; i++)
        printf("%d%c", a[i], " \n"[i==cnt]);
    return 0;
}