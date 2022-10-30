#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=62,maxm=105;
char s[maxm][maxm];
int a[maxm][maxm];
int b[maxn];
int x,y,n,m;
char tc(int n){
    if (n<26) return 'A'+n;
    n-=26;
    if (n<26) return 'a'+n;
    n-=26;
    if (n<10) return '0'+n;
    n-=10;
    return ' ';
}
bool next(){
    y+=(x&1)?-1:1;
    if (y==-1){
        x++; y=0;
    }
    if (y==m){
        x++; y=m-1;
    }
    return x<n;
}
int main(){
    int tt;
    int i,j,k;
    int p,cnt;
    scanf("%d",&tt);
    while (tt--){
        scanf("%d%d%d",&n,&m,&k);
        for (i=0;i<n;i++) scanf("%s",s[i]);
        cnt=0;
        for (i=0;i<n;i++) for (j=0;j<m;j++)
            cnt+=s[i][j]=='R';
        for (i=0;i<k;i++) b[i]=cnt/k;
        for (i=0;i<cnt%k;i++) b[i]++;
        x=-1; y=0; p=0;
        while (next()){
            if (s[x][y]=='.'){
                a[x][y]=p; continue;
            }
            if (!b[p]) p++;
            b[p]--; a[x][y]=p;
        }
        for (i=0;i<n;i++){
            for (j=0;j<m;j++)
                putchar(tc(a[i][j]));
            puts("");
        }
    }
    return 0;
}