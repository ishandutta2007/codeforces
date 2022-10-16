#include<bits/stdc++.h>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define BIT(x,i) (((x)>>(i))&1)
using namespace std;
char s[MAX][MAX];
int a[MAX][MAX];
int b[MAX][MAX];
int m,n;
void init(void) {
    scanf("%d%d",&m,&n);
    REP(i,m) scanf("%s",s[i]);
    REP(i,m) REP(j,n) a[i][j]=s[i][j]-49;
}
bool okrow(int s) {
    REP(i,m) {
        vector<int> v;
        REP(j,4) if (BIT(s,j)==i%2) v.push_back(j);
        bool fix=false;
        REP(j,n) {
            if (a[i][j]<0) continue;
            if (BIT(s,a[i][j])!=i%2) return (false);
            if (fix && a[i][j]!=v[j%2]) return (false);
            fix=true;
            if (a[i][j]!=v[j%2]) reverse(v.begin(),v.end());
        }
        REP(j,n) b[i][j]=v[j%2];
    }
    REP(i,m) {
        REP(j,n) printf("%d",b[i][j]+1);
        printf("\n");
    }
    return (true);
}
bool okcol(int s) {
    REP(j,n) {
        vector<int> v;
        REP(i,4) if (BIT(s,i)==j%2) v.push_back(i);
        bool fix=false;
        REP(i,m) {
            if (a[i][j]<0) continue;
            if (BIT(s,a[i][j])!=j%2) return (false);
            if (fix && a[i][j]!=v[i%2]) return (false);
            fix=true;
            if (a[i][j]!=v[i%2]) reverse(v.begin(),v.end());
        }
        REP(i,m) b[i][j]=v[i%2];
    }
    REP(i,m) {
        REP(j,n) printf("%d",b[i][j]+1);
        printf("\n");
    }
    return (true);
}
void process(void) {
    REP(i,4) FOR(j,i+1,3) {
        int s=(1<<i)|(1<<j);
        if (okrow(s)) return;
        if (okcol(s)) return;
    }
    printf("0");
}
int main(void) {
    init();
    process();
    return 0;
}