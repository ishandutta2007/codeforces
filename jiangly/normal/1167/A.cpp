// remote judge by luogu
#include<bits/stdc++.h>
const int MAXN=105;
int t,n;
char a[MAXN];
bool check(){
    for(int i=0;i<n-10;++i)
        if(a[i]=='8')
            return 1;
    return 0;
}
int main(){
    scanf("%d",&t);
    for(;t;--t){
        scanf("%d",&n);
        scanf("%s",a);
        if(check())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}