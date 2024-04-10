#include<bits/stdc++.h>
using namespace std;
const string no="Poor Inna and pony!";
const int INF=(int)1e9+7;
int m,n,x,y,a,b;
int abs(int x) {
    if (x<0) return (-x); else return (x);
}
int step(int u,int v) {
    if (x==u && y==v) return (0);
    if ((x-u)%a!=0) return (INF);
    if ((y-v)%b!=0) return (INF);
    int sx=abs(x-u)/a;
    int sy=abs(y-v)/b;
    if (sx==0) {
        if (x-a<1 && x+a>m) return (INF);
    }
    if (sy==0) {
        if (y-b<1 && y+b>n) return (INF);
    }
    if ((sx-sy)%2!=0) return (INF);
    return (max(sx,sy));
}
int main(void) {
    cin >> m >> n >> x >> y >> a >> b;
    int res=INF;
    res=min(res,step(1,1));
    res=min(res,step(1,n));
    res=min(res,step(m,1));
    res=min(res,step(m,n));
    if (res<INF) cout << res; else cout << no;
    return 0;
}