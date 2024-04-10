#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
#include <ctime> 
#include <cstdlib>
#include <set>
#include <sstream>
#include <queue>
#include <functional>
#include <memory>
#include <assert.h>

#define sqr(x) ((x)*(x))
#define ll long long

using namespace std;

#pragma comment(linker,"/STACK:64000000")

const int maxn=1600, mod=1000000007;
const double eps=1e-9;
const ll q=239;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};


int n,m,cnt,ans;
char a[maxn][maxn];
vector<bool> vis(1000000000,false);

bool find(ll x) {
    return vis[((x+mod*10000LL)*997LL)%999988973];
}

void add(ll x) {
    vis[((x+mod*10000LL)*997LL)%999988973]=1;
}

int norm(int x, int y) {
    if (x<0) {
        x=-x;
        x%=y;
        x=y-x;
        if (x==y) x=0;
    } else {
        x%=y;
    }
    return x;
}

void dfs(int x, int y) {
    int nx=norm(x,n);
    int ny=norm(y,m);
    if (a[nx][ny]=='#' || find(x*1600+y)) return;
    cnt++;
    if (cnt==ans+1) {
        cout << "Yes";
        exit(0);
    }
    add(x*1600+y);
    for (int i=0; i<4; i++) {
        dfs(x+dx[i],y+dy[i]);
    }
}

int main() { 
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int cx,cy;

    scanf("%d%d\n",&n,&m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            a[i][j]=getchar();
            if (a[i][j]=='S') {
                cx=i; cy=j;
            }
            ans+=a[i][j]!='#';
        }
        scanf("\n");
    }
    dfs(cx,cy);
    cout << "No";

    return 0;
}