#include<bits/stdc++.h>
using namespace std;
int n,albet[6],t,m,subset[64],
neisz[64],
mask[100005];
char r[10],output[100005];
bool tryplace(int i,int t){
 --albet[t];
 for(int k=0;k<64;++k){if(k>>t&1)--subset[k];
 if(mask[i]&k)--neisz[k];}
 for(int k=0;k<64;++k){
  if(neisz[k]<subset[k]){
   goto undo;
  }
 }
 return output[i]='a'+t;
undo:for(int k=0;k<64;++k){
 if(k>>t&1)++subset[k];
 if(mask[i]&k)++neisz[k];}
 ++albet[t];
 return 0;
}
int main(){
 while((t=getchar())!='\n')++n,++albet[t-'a'];
 for(int i=0;i<64;++i)for(int j=0;j<6;++j)if(i>>j&1)subset[i]+=albet[j];
 fill(mask,mask+n,(1<<6)-1);
 int ___L___59;scanf("%d",&___L___59);while(___L___59--){
  scanf("%d",&t);scanf("%s",r);m=0;
 for(int i=0;i<strlen(r);++i)m|=1<<r[i]-'a';
 mask[--t]=m;
 }
 for(int i=0;i<n;++i)for(int k=0;k<64;++k)if(mask[i]&k)++neisz[k];
 for(int i=0;i<n;++i){
  for(int j=0;j<6;++j)if(mask[i]>>j&1&&albet[j]&&tryplace(i,j))goto nx;
  return puts("Impossible"),0;
  nx:;
 }
 puts(output);
}