#include <bits/stdc++.h>
using namespace std;

long long c2(int n){return (long long)n*(n-1)/2;}
const int BS=18;
void bitadd(int *bit,int i,int v)
{
  int p=i+1;
  while(p<1<<BS){
    bit[p]+=v;
    p+=p&-p;
  }
}

int bitsum(int *bit,int i)
{
  int p=i,ret=0;
  while(p>0){
    ret+=bit[p];
    p-=p&-p;
  }
  return ret;
}


int main()
{
  int n,q;
  scanf("%d%d",&n,&q);
  vector<int> p(n);
  for(int i=0;i<n;i++){
    scanf("%d",&(p[i]));
    p[i]--;
  }
  vector<int> x1(q),y1(q),x2(q),y2(q);
  for(int i=0;i<q;i++){
    scanf("%d%d%d%d",&(x1[i]),&(y1[i]),&(x2[i]),&(y2[i]));
    x1[i]--,y1[i]--;
  }
  vector<long long> ans(q);
  vector<vector<int> > qr1(n+1),qr2(n+1);
  for(int i=0;i<q;i++){
    ans[i]=c2(n)-c2(x1[i])-c2(y1[i])-c2(n-x2[i])-c2(n-y2[i]);
    qr1[x1[i]].push_back(i);
    qr2[x2[i]].push_back(i);
    //printf("%lld\n",ans[i]);
  }
  static int bit[1<<18]={0};
  for(int t=0;t<n;t++){
    for(int s=0;s<qr1[t].size();s++){
      int i=qr1[t][s];
      int ct1=bitsum(bit,y1[i]),ct2=t-bitsum(bit,y2[i]);
      ans[i]+=c2(ct1)+c2(ct2);
      //printf("%d %d %d\n",i,ct1,ct2);
    }
    for(int s=0;s<qr2[t].size();s++){
      int i=qr2[t][s];
      int ct1=y1[i]-bitsum(bit,y1[i]),ct2=(n-y2[i])-(t-bitsum(bit,y2[i]));
      ans[i]+=c2(ct1)+c2(ct2);
      //printf("%d %d %d\n",i,ct1,ct2);
    }
    bitadd(bit,p[t],1);
  }
  for(int i=0;i<q;i++){
    printf("%lld\n",ans[i]);
  }
  return 0;
}