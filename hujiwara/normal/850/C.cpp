#include <bits/stdc++.h>
using namespace std;


unordered_map<long long,int> M;

int gn(long long I)
{
  unordered_map<long long,int>::iterator it=M.find(I);
  if(it!=M.end()){
    return it->second;
  }
  bool B[64]={0};
  for(int i=0;i<64;i++){
    if((I>>i)==0)break;
    long long J=(I&((1ll<<i)-1))|(I>>(i+1));
    B[gn(J)]=1;
  }
  int ret=0;
  while(B[ret])ret++;
  M[I]=ret;
  return ret;
}

int main()
{
  int n;
  scanf("%d",&n);
  vector<int> a(n);
  for(int i=0;i<n;i++){
    scanf("%d",&(a[i]));
  }
  vector<int> P;
  for(int i=0;i<n;i++){
    int N=a[i];
    for(int j=2;j*j<=N;j++){
      if(N%j==0){
	P.push_back(j);
	while(N%j==0){
	  N/=j;
	}
      }
    }
    if(N>1){
      P.push_back(N);
    }
  }
  sort(P.begin(),P.end());
  int g=0;
  for(int t=0;t<P.size();t++){
    if(t>0&&P[t-1]==P[t])continue;
    int p=P[t];
    long long I=0;
    for(int i=0;i<n;i++){
      int k=0,N=a[i];
      while(N%p==0){
	k++;
	N/=p;;
      }
      if(k>0){
	I|=1<<(k-1);
      }
    }
    g^=gn(I);
  }
  puts(g==0?"Arpa":"Mojtaba");
  return 0;
}