#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
char s[100010],sss[100010],ch[100010];
int st[100010],ed[100010],n,r[100010],c[100010],mo=1000000007,b[10],a[10];
int quick(int k1,int k2,int k3){
    int ans=1;
    while(k2){if(k2&1) ans=1ll*ans*k1%mo; k2=k2/2; k1=1ll*k1*k1%mo;}
    return ans;
}
int main(){
    scanf("%s",ch+1); for(int i=0;i<10;i++)b[i]=1; for(int i=0;i<10;i++)a[i]=i;
    scanf("%d",&n); int tot=0;
    for(int i=1;i<=n;i++){
        scanf("%s",sss+1); r[i]=sss[1]-48;
        int k1=strlen(sss+1);
        if(k1==3){st[i]=1; ed[i]=0; continue;}
        st[i]=tot+1; for(int j=4;j<=k1;j++)c[++tot]=sss[j]-48; ed[i]=tot;
    }
    for(int i=n;i;i--){
        int kk=0,k1=0;
        for(int j=st[i];j<=ed[i];j++){kk=(1ll*kk*quick(10,b[c[j]],mo)+a[c[j]])%mo; k1+=b[c[j]]; if(k1>=mo-1) k1-=mo-1;}
        b[r[i]]=k1; a[r[i]]=kk;
    }
    int len=strlen(ch+1),kk=0;
    for(int i=1;i<=len;i++)kk=(1ll*quick(10,b[ch[i]-48],mo)*kk+a[ch[i]-48])%mo;
    cout<<kk<<endl;
    return 0;
}