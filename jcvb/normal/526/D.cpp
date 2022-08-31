#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
#define mo 1000000007
typedef long long ll;
int qp(int a,int b){
    int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);
    return ans;
}

int n,k;
char s[1000005];
int pre[1000005];
void kmp(){
    pre[1]=0;
    for (int i=2,j=0;i<=n;i++){
        while(j && s[j+1]!=s[i])j=pre[j];
        if(s[j+1]==s[i])j++;
        pre[i]=j;
    }
}
inline int test(int x){
    int len=x-pre[x];
    int r=x/len,rr=(x-1)/len+1;
    int rig=r/k,lef=(rr-1)/(k+1)+1;
    return lef<=rig;
}
int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    kmp();
    for (int i=1;i<=n;i++)putchar('0'+test(i));
    putchar('\n');
    return 0;
}