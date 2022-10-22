#include<bits/stdc++.h>
using namespace std;
char s[110][110];
int n,a[110],ans,Ans[110];
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    while (true){
        int u=0;
        for (int i=1;i<=n;i++)
            if (!a[i]) u=i;
        if (!u) break;
        Ans[++ans]=u;
        for (int i=1;i<=n;i++)
            if (s[u][i]!='0') a[i]--;
    }
    printf("%d\n",ans);
    for (int i=1;i<=ans;i++) printf("%d ",Ans[i]);
    return 0;
}