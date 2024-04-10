#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

int vis[MAXN];

long long pw(int p, int q){
    if (!q)
        return 1LL;
    long long tt = pw(p, q/2);
    tt = (tt * tt) % MM;
    if (q & 1)
        return (tt * p ) %MM;
    else
        return tt;
}

int main(){
    int p, k;
    cin>>p>>k;
    for(int i = 0; i <= p; i++)
        vis[i] = 0;
    if (k == 0){
        cout<<pw(p, p-1) % MM<<endl;
    }
    else
        if (k == 1){
            cout<<pw(p, p) % MM <<endl;
        }
        else{
            int cnt = 0;
            for(int i = 1; i < p; i++)
                if (!vis[i]){
                    cnt++;
                    vis[i] = 1;
                    long long x = ((long long)i * k) % p;
                    while(!vis[x]){
                        vis[x] = 1;
                        x = (x * k) % p;
                    }
                }
            cout<<pw(p, cnt) % MM <<endl;
        }
    return 0;
}