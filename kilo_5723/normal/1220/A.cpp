#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e5+5;
char s[maxn];
int main(){
    int i,n,a,b;
    scanf("%d",&n);
    scanf("%s",s);
    a=0; b=0;
    for (i=0;i<n;i++){
        if (s[i]=='z') a++;
        if (s[i]=='n') b++;
    }
    while (b--) printf("1 ");
    while (a--) printf("0 ");
    puts("");
    return 0;
}