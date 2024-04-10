#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e5+5,lim=1e4;
int cnt[lim];
int main(){
    int tt;
    int i,j,n;
    scanf("%d",&tt);
    while (tt--){
        scanf("%d",&n);
        for (i=0;i<lim;i++) cnt[i]=0;
        for (i=lim-1;i>1;i--) while (n>=i*(i-1)/2){
            n-=i*(i-1)/2; cnt[i]++;
        }
        putchar('1');
        for (i=1;i<lim;i++){
            putchar('3');
            for (j=0;j<cnt[i];j++) putchar('7');
        }
        puts("");
    }
    return 0;
}