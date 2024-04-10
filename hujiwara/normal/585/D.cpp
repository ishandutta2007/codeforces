#include <bits/stdc++.h>
using namespace std;
const int INF=1000000000;

int main()
{
  int n;
  scanf("%d",&n);
  int L[30],M[30],W[30];
  for(int i=0;i<n;i++){
    scanf("%d%d%d",L+i,M+i,W+i);
  }
  int n1=n/2,n2=n-n1;
  int P3[15];
  P3[0]=1;
  for(int i=1;i<=n2;i++){
    P3[i]=P3[i-1]*3;
  }
  static pair<pair<int,int>,pair<int,int> > P[531441];
  for(int I=0;I<P3[n1];I++){
    int l=0,m=0,w=0;
    for(int i=0;i<n1;i++){
      int t=I/P3[i]%3;
      if(t!=0){
	l+=L[i];
      }
      if(t!=1){
	m+=M[i];
      }
      if(t!=2){
	w+=W[i];
      }
    }
    P[I]=make_pair(make_pair(m-l,w-l),make_pair(l,I));
  }
  sort(P,P+P3[n1]);
  int Ml=-INF,I1,I2;
  for(int I=0;I<P3[n2];I++){
    int l=0,m=0,w=0;
    for(int i=0;i<n2;i++){
      int t=I/P3[i]%3;
      if(t!=0){
	l+=L[n1+i];
      }
      if(t!=1){
	m+=M[n1+i];
      }
      if(t!=2){
	w+=W[n1+i];
      }
    }
    int t=upper_bound(P,P+P3[n1],make_pair(make_pair(l-m,l-w),make_pair(INF,0)))-P-1;
    if(t>=0&&P[t].first==make_pair(l-m,l-w)&&Ml<l+P[t].second.first){
      Ml=l+P[t].second.first;
      I1=P[t].second.second;
      I2=I;
    }
  }
  if(Ml==-INF){
    puts("Impossible");
  }
  else{
    for(int i=0;i<n;i++){
      int t=(i<n1?I1/P3[i]%3:I2/P3[i-n1]%3);
      puts(t==0?"MW":t==1?"LW":"LM");
    }
  }
  return 0;
}