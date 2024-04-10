#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,a,b,k;
  scanf("%d%d%d%d",&n,&a,&b,&k);
  static char s[200010];
  scanf("%s",s);
  int T=0;
  int C=0;
  vector<int> V;
  for(int i=0;i<=n;i++){
    if(i==n||s[i]=='1'){
      C+=T/b;
      for(int k=0;k<T/b;k++){
	V.push_back(i-T+k*b+b-1);
      }
      T=0;
    }
    else{
      T++;
    }
  }
  int ret=C-a+1;
  printf("%d\n",ret);
  for(int k=0;k<ret;k++){
    printf("%d%c",V[k]+1,k==ret-1?'\n':' ');
  }
  return 0;
}