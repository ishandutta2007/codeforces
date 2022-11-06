#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,tot,ans;
char str[N];
int main(){
    scanf("%d%s",&n,str+1);
    for(int i=1;i<=n;i++){
        if(str[i]=='x')++tot;
        else ans+=max(tot-2,0),tot=0;
    }
    ans+=max(tot-2,0);
    printf("%d",ans);
    return 0;
}