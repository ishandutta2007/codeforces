#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e6+5;
char s[maxn];
int main(){
    int i,n,cur=0,ans=0;
    scanf("%d",&n);
    scanf("%s",s);
    for (i=0;i<n;i++){
        if (s[i]==')'){
            if (cur<=0) ans++;
            cur--;
        }
        else {
            cur++;
            if (cur<=0) ans++;
        }
    }
    if (cur!=0) puts("-1");
    else printf("%d\n",ans);
    return 0;
}