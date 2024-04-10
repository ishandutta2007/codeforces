#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;

bitset<100001>f[26],ans;
int q[300001],h,t;
char tem[300001],str[100001];
int n,m;
int main(){
    scanf("%s",str+1);
    n=strlen(str+1);
    for(int i=1;i<=n;i++)f[str[i]-'a'].set(i);
    int q;
    scanf("%d",&q);
    int opt,j,c,l,r;
    ans.set();
    for(int i=1;i<=q;i++){
        scanf("%d",&opt);
        if(opt==1){
            scanf("%d",&j);
            char ch=getchar();
            while(ch<'a'||ch>'z')ch=getchar();
            f[str[j]-'a'][j]=0;
            f[ch-'a'][j]=1;
            str[j]=ch;
        }
        else{
            scanf("%d%d%s",&l,&r,tem+1);
            int len=strlen(tem+1);
            ans.set();
            for(int j=1;j<=len;j++)
                ans&=(f[tem[j]-'a']>>(j-1));
            printf("%d\n",max(int((ans>>(l)).count()-(ans>>(r-len+2)).count()),0));
        }
    }
}