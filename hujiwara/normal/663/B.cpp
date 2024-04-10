#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  scanf("%d",&t);
  long long P[11],D[11];
  P[0]=D[0]=1ll;
  for(int i=1;i<=10;i++){
    P[i]=P[i-1]*10;
    D[i]=D[i-1]+P[i];
  }
  while(t--){
    char S[20];
    scanf("%s",S);
    int n=0;
    int N=0;
    for(int i=4;S[i];i++){
      n++;
      N=10*N+(S[i]-'0');
    }
    long long R=1989+D[n-1]-1,A;
    //printf("%lld\n",R);
    if(R%P[n]<=N){
      A=R+(N-R%P[n]);
    }
    else{
      A=R+(N-R%P[n])+P[n];
    }
    printf("%lld\n",A);
  }
  return 0;
}