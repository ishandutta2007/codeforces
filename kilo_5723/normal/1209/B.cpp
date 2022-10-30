#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=105,lim=2e4;
int a[maxn],b[maxn];
char s[maxn];
int cnt(){
    int ans=0;
    for (int i=0;s[i];i++) if (s[i]=='1') ans++;
    return ans;
}
int main(){
    int i,j,n;
    int ans;
    scanf("%d",&n);
    scanf("%s",s); ans=cnt();
    for (i=0;i<n;i++)
        scanf("%d%d",&a[i],&b[i]);
    for (i=0;i<lim;i++){
        for (j=0;j<n;j++) if (i>=b[j]&&(i-b[j])%a[j]==0)
            s[j]^=1;
        ans=max(ans,cnt());
    }
    printf("%d\n",ans);
    return 0;
}