#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e5+5;
char a[maxn],b[maxn];
int main(){
    int tt;
    int n,m,k;
    scanf("%d",&tt);
    while (tt--){
        scanf("%s%s",a,b);
        n=strlen(a)-1; m=strlen(b)-1; k=m;
        while (b[k]=='0') k--;
        n=n-m+k; k=0;
        while (a[n-k]=='0') k++;
        printf("%d\n",k);
    }
    return 0;
}