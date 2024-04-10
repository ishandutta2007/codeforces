#include<bits/stdc++.h>
#define MAX   1000000
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
using namespace std;
typedef long long ll;
int m,n,k;
ll res;
int main(void) {
    cin>>m>>n>>k;
    res=-1;
    if (m+n-2<k) {
        cout<<-1;
        return 0;
    }
    int maxx=min(k,n-1);
    int maxy=min(k,m-1);
    int minx=max(0,k-maxy);
    int miny=max(0,k-maxx);
    FOR(x,minx,minx+MAX) {
        int y=k-x;
        if (x<n && x>=0 && y<m && y>=0) res=max(res,1LL*(n/(x+1))*(m/(y+1)));
    }
    FOR(y,miny,miny+MAX) {
        int x=k-y;
        if (y<m && y>=0 && x<n && x>=0) res=max(res,1LL*(n/(x+1))*(m/(y+1)));
    }
    FOR(x,maxx-MAX,maxx) {
        int y=k-x;
        if (x<n && x>=0 && y<m && y>=0) res=max(res,1LL*(n/(x+1))*(m/(y+1)));
    }
    FOR(y,maxy-MAX,maxy) {
        int x=k-y;
        if (y<m && y>=0 && x<n && x>=0) res=max(res,1LL*(n/(x+1))*(m/(y+1)));
    }
    cout<<res;
    return 0;
}