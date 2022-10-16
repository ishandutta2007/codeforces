#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int a[MAX],n,l,x,y;
void init(void) {
    scanf("%d%d%d%d",&n,&l,&x,&y);
    FOR(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
}
bool canHave(int pos,int x) {
    if (binary_search(a+1,a+n+1,pos-x)) return (true);
    if (binary_search(a+1,a+n+1,pos+x)) return (true);
    return (false);
}
void process(void) {
    bool okX=false;
    bool okY=false;
    FOR(i,1,n) {
        if (binary_search(a+1,a+n+1,a[i]-x)) okX=true;
        if (binary_search(a+1,a+n+1,a[i]+x)) okX=true;
        if (binary_search(a+1,a+n+1,a[i]-y)) okY=true;
        if (binary_search(a+1,a+n+1,a[i]+y)) okY=true;
    }
    if (okX && okY) {
        printf("0");
        return;
    }
    if (okX) {
        printf("1\n%d",y);
        return;
    }
    if (okY) {
        printf("1\n%d",x);
        return;
    }
    FOR(i,1,n) {
        int tmp=a[i]+x;
        if (0<=tmp && tmp<=l && canHave(tmp,y)) {
            printf("1\n%d",tmp);
            return;
        }
        tmp=a[i]-x;
        if (0<=tmp && tmp<=l && canHave(tmp,y)) {
            printf("1\n%d",tmp);
            return;
        }
        tmp=a[i]+y;
        if (0<=tmp && tmp<=l && canHave(tmp,x)) {
            printf("1\n%d",tmp);
            return;
        }
        tmp=a[i]-y;
        if (0<=tmp && tmp<=l && canHave(tmp,x)) {
            printf("1\n%d",tmp);
            return;
        }
    }
    printf("2\n%d %d",x,y);
}
int main(void) {
    init();
    process();
    return 0;
}