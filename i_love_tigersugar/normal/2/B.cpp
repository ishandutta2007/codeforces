#include<bits/stdc++.h>
#define MAX   1111
const int INF=(int)1e7;
struct num {
    int pw2,pw5;
    num(){
        pw2=INF;
        pw5=INF;
    }
    num(const int &x,const int &y) {
        pw2=x;pw5=y;
    }
    num(const int &x) {
        if (x==0) {
            pw2=INF;
            pw5=INF;
            return;
        }
        int t;
        t=x;
        pw2=0;
        while (t%2==0) {
            pw2++;
            t=t/2;
        }
        t=x;
        pw5=0;
        while (t%5==0) {
            pw5++;
            t=t/5;
        }
    }   
    num operator + (const num &x) const {
        return (num(pw2+x.pw2,pw5+x.pw5));
    }
    bool operator == (const num &x) const {
        return (pw2==x.pw2 && pw5==x.pw5);
    }
    int val(void) const {
        if (pw2<pw5) return (pw2); else return (pw5);
    }
};
num min2(const num &x,const num &y) {
    if (x.pw2<y.pw2) return (x);
    if (y.pw2<x.pw2) return (y);
    if (x.pw5<y.pw5) return (x); else return (y);
}
num min5(const num &x,const num &y) {
    if (x.pw5<y.pw5) return (x);
    if (y.pw5<x.pw5) return (y);
    if (x.pw2<y.pw2) return (x); else return (y);
}
int n;
bool zero;
int zx,zy;
num a[MAX][MAX];
num f[MAX][MAX];
num g[MAX][MAX];
char r[2*MAX];
void init(void) {
    scanf("%d",&n);
    int i,j,t;
    zero=false;
    for (i=1;i<=n;i=i+1)
        for (j=1;j<=n;j=j+1) {
            scanf("%d",&t);
            a[i][j]=num(t);
            if (t==0) {
                zero=true;
                zx=i;
                zy=j;
            }
        }
    for (i=0;i<=n;i=i+1) {
        f[i][0]=num();
        f[0][i]=num();
        g[i][0]=num();
        g[0][i]=num();
    }
}
void optimize(void) {
    int i,j;
    for (i=1;i<=n;i=i+1)
        for (j=1;j<=n;j=j+1) {
            if  (i==1 && j==1) {
                f[i][j]=a[i][j];
                g[i][j]=a[i][j];
            }
            else {
                f[i][j]=min2(f[i-1][j],f[i][j-1])+a[i][j];
                g[i][j]=min5(g[i-1][j],g[i][j-1])+a[i][j];
            }
        }
}
void trace(void) {
    int i,j,t;  
    if (zero && f[n][n].val()>=1 && g[n][n].val()>=1) {
        printf("1\n");
        for (i=1;i<zx;i=i+1) printf("D");
        for (i=1;i<zy;i=i+1) printf("R");
        for (i=zx;i<n;i=i+1) printf("D");
        for (i=zy;i<n;i=i+1) printf("R");
        return;
    }
    i=n;
    j=n;
    t=0;
    if (f[n][n].val()<g[n][n].val()) {
        printf("%d\n",f[n][n].val());
        while (i>1 || j>1) {
            t++;
            if (f[i][j]==f[i-1][j]+a[i][j]) {
                r[t]='D';
                i=i-1;              
            }
            else {
                r[t]='R';
                j=j-1;
            }
        }       
    }
    else {
        printf("%d\n",g[n][n].val());
        while (i>1 || j>1) {
            t++;
            if (g[i][j]==g[i-1][j]+a[i][j]) {
                r[t]='D';
                i=i-1;
            }
            else {
                r[t]='R';
                j=j-1;
            }
        }
    }
    for (i=t;i>=1;i=i-1) printf("%c",r[i]);
}
int main(void) {
    init();
    optimize();
    trace();
    return 0;
}