#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
char a[22],b[22][22];
bool ok(int m,int n) {
    REP(i,m) REP(j,n) b[i][j]=a[i*n+j];
    REP(j,n) {
        bool all=true;
        REP(i,m) if (b[i][j]!='X') all=false;
        if (all) return (true);
    }
    return (false);
}
void process(void) {
    scanf("%s",a);
    int l=strlen(a);
    vector<int> v;
    FOR(i,1,l) if (l%i==0 && ok(i,l/i)) v.push_back(i);
    printf("%d",v.size());
    FORE(it,v) printf(" %dx%d",*it,l/(*it));
    printf("\n");
}
int main(void) {
    int t;
    scanf("%d",&t);
    REP(i,t) process();
    return 0;
}