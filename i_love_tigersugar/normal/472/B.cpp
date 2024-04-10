#include<bits/stdc++.h>
#define MAX   2222
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
using namespace std;
int h[MAX];
int n,q;
inline int ceil(int a,int b) {
    return (a/b+(a%b>0));
}
int main(void) {
    int res=0;
    scanf("%d%d",&n,&q);
    FOR(i,1,n) scanf("%d",&h[i]);
    FOR(i,1,MAX) {
        int cnt=0;
        FOR(j,1,n) if (h[j]>i) cnt++;
        if (cnt==0) break;
        res+=2*ceil(cnt,q);
    }
    printf("%d",res);
    return 0;
}