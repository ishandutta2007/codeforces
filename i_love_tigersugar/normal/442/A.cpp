#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define BIT(x,i) (((x)>>(i))&1)
using namespace std;
const int n=5;
const char type[]="RGBYW";
int c[11][11],cx[11],cy[11];
inline int order(char c) {
    REP(i,5) if (type[i]==c) return (i);
    assert(false);
}
bool know(int st,int sn) {
    REP(i,5) REP(j,5) REP(k,5) REP(l,5) if (c[i][j]>0 && c[k][l]>0) {
        if (i==k && j==l) continue;
        if (i==k) {
            if (!BIT(sn,j) && !BIT(sn,l)) return (false);
        }
        if (j==l) {
            if (!BIT(st,i) && !BIT(st,k)) return (false);
        }
        if (BIT(st,i) || BIT(sn,j)) continue;
        if (BIT(st,k) || BIT(sn,l)) continue;
        return (false);
    }
    return (true);
}
inline int bitcount(int x) {
    int ret=0;
    REP(i,5) if (BIT(x,i)) ret++;
    return (ret);
}
void init(void) {
    char s[3];
    int k;
    scanf("%d",&k);
    REP(zz,k) {
        scanf("%s",s);
        c[order(s[0])][s[1]-'1']++;
        cx[order(s[0])]++;
        cy[s[1]-'1']++;
    }
    int res=210000;
    //cerr<<know(0,0)<<endl;
    REP(i,1<<5) REP(j,1<<5) if (know(i,j)) res=min(res,bitcount(i)+bitcount(j));
    printf("%d",res);
}
int main(void) {
    init();
    return 0;
}