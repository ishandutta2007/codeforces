#include<bits/stdc++.h>
#define MAX   333
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
int m,n,k;
void process(void) {
    queue<ii> q;
    scanf("%d%d%d",&m,&n,&k);
    FOR(i,1,m) {
        if (i&1) FOR(j,1,n) q.push(ii(i,j));
        else FORD(j,n,1) q.push(ii(i,j));
    }
    REP(i,k) {
        int t=i?2:m*n-2*k+2;
        printf("%d",t);
        REP(zz,t) {
            printf(" %d %d",q.front().fi,q.front().se);
            q.pop();
        }
        printf("\n");
    }
}
int main(void) {
    process();
    return 0;
}