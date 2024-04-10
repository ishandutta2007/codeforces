#include<cstdio>
#include<cstring>
#define MAX   111
int a[MAX];
int b[MAX];
int f[MAX][10];
int t[MAX][10];
bool c[MAX];
int n;
int stt(int x) {
    int c=x%10>0;
    x=x/10;
    int b=x%10>0;
    x=x/10;
    int a=x%10>0;
    return ((a<<2)|(b<<1)|c);
}
void init(void) {
    scanf("%d",&n);
    int i;
    for (i=1;i<=n;i=i+1) {
        scanf("%d",&a[i]);
        b[i]=stt(a[i]);     
    }
}
void optimize(void) {
    memset(f,-1,sizeof f);
    f[0][0]=0;
    int i,j;
    for (i=0;i<n;i=i+1)
        for (j=0;j<8;j=j+1)
            if (f[i][j]>=0) {
                if (f[i+1][j]<f[i][j]) {
                    f[i+1][j]=f[i][j];
                    t[i+1][j]=j;
                }
                if ((j&b[i+1])==0)
                    if (f[i+1][j|b[i+1]]<f[i][j]+1) {
                        f[i+1][j|b[i+1]]=f[i][j]+1;
                        t[i+1][j|b[i+1]]=j;
                    }
            }
}
void trace(void) {
    int j=0;
    int i;
    for (i=0;i<8;i=i+1)
        if (f[n][i]>f[n][j]) j=i;
    int res=0;
    i=n;
    while (f[i][j]>0) {
        c[i]=f[i][j]-f[i-1][t[i][j]];
        res=res+c[i];
        j=t[i][j];
        i--;
    }
    bool sp=false;
    printf("%d\n",res);
    for (i=1;i<=n;i=i+1)
        if (c[i]) {
            if (sp) printf(" ");
            sp=true;
            printf("%d",a[i]);
        }
}
int main(void) {
    init();
    optimize();
    trace();
    return 0;   
}