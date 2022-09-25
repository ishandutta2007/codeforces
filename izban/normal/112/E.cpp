#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int gcd(int a, int b) {
    while (b) b^=a^=b^=a%=b;
    return a;
}

const int maxn=100100;
const int inf=1000000;
const double eps=1e-9;

int n,m,ans=inf;
int d[50][1<<6][1<<6];

bool check(int mask1, int mask2, int mask3, int j) {
    bool res=mask2 & (1<<j);
    res|=j && (mask2 & (1<<(j-1)));
    res|=j<m-1 && (mask2 & (1<<(j+1)));
    res|=mask1 & (1<<j);
    res|=mask3 & (1<<j);
    return res;
}

int cnt(int mask) {
    int res=0;
    for (int i=1; i<=mask; i<<=1)
        res+=(mask&i)>0;
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    for (int i=0; i<50; i++) for (int j=0; j<1<<6; j++) for (int k=0; k<1<<6; k++) d[i][j][k]=inf;

    cin >> n >> m;
    if (n<m) swap(n,m);
    d[0][(1<<m)-1][0]=0;
    for (int i=0; i<n; i++) {
        for (int mask1=0; mask1<1<<m; mask1++) {
            for (int mask2=0; mask2<1<<m; mask2++) {
                for (int mask3=0; mask3<1<<m; mask3++) {
                     bool f=true;
                     for (int j=0; j<m; j++) f&=check(mask1,mask2,mask3,j);
                     if (f) d[i+1][mask2][mask3]=min(d[i+1][mask2][mask3],d[i][mask1][mask2]+cnt(mask3));
                     for (int j=0; j<m; j++) f&=check(mask2,mask3,0,j);
                     if (i==n-1 && f) ans=min(ans,d[i+1][mask2][mask3]);
                }
            }
        }
    }
    cout << n*m-ans;
    return 0;
}