/*
MikeMirzayanov's family will be attacked and will all die!!!!!!
*/
#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
int j,n,sa[2001010],lst[2001010],rk[2001100],tot,i,len;
char S[2001010];
bool cmp(int x,int y){
	return ((rk[x]<rk[y])||((rk[x]==rk[y])&&(rk[x^len]<rk[y^len])));
}
int main()
{
	n=read();
 scanf("%s",S+1);n=strlen(S+1);
 for (i=0;i<n;i++) sa[i]=i;
 for (i=0;i<n;i++) rk[i]=S[i+1]-'a'+1;len=0;
 sort(sa,sa+n,cmp);
 for (i=0;i<n;i++) lst[i]=rk[i];tot=0;
 for (i=0;i<n;i++)
 	if ((lst[sa[i]]==lst[sa[i-1]])&&(lst[sa[i]^len]==lst[sa[i-1]^len])) rk[sa[i]]=tot;
 	else rk[sa[i]]=++tot;
 for (len=1;len<n;len<<=1){
    sort(sa,sa+n,cmp);
 	for (i=0;i<n;i++) lst[i]=rk[i];tot=0;
 	for (i=0;i<n;i++)
 	    if ((i!=0)&&((lst[sa[i]]==lst[sa[i-1]])&&(lst[sa[i]^len]==lst[sa[i-1]^len]))) rk[sa[i]]=tot;
 	    else rk[sa[i]]=++tot;
 }
 for (i=0;i<n;i++)
     if (rk[i]==1){
        for (j=0;j<n;j++)
           printf("%c",S[(i^j)+1]);
      	return 0;
	 }
 // for (i=1;i<=n;i++) printf("%d ",sa[i]);puts("");
 return 0;
}