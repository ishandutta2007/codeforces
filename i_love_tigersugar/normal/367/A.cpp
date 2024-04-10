#include<cstdio>
#include<cstring>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
char a[MAX];
int c[MAX][4];
int n,q;
void init(void) {
    scanf("%s",a+1);
    n=strlen(a+1);
    scanf("%d",&q);
    FOR(i,1,n) REP(j,3) c[i][j]=c[i-1][j]+(a[i]=='x'+j);    
}
int cmod(const int &r,const int &d) {   
    if (r<3) return (r>=d);
    return ((r-d)/3+1);
}
int count(const int &l,const int &r,const int &x) {
    if (l>r) return (0);
    return (c[r][x]-c[l-1][x]);
}
void check(const int &l,const int &r) { 
    if (r-l<2) {
        printf("YES\n");
        return;
    }
    bool ok=false;
    REP(i,3) {
        ok=true;
        REP(j,3) if (cmod(r-l,j)!=count(l,r,(2-j+i)%3)) {
            ok=false;
            break;
        }
        if (ok) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}
void answer(void) {
    int l,r;
    REP(i,q) {
        scanf("%d",&l);
        scanf("%d",&r);
        check(l,r);
    }
}
int main(void) {
    init();
    answer();
    return 0;
}