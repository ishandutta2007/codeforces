#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  static char s[300000];
  scanf("%s",s);
  stack<int> S;
  vector<int> X(n);
  for(int i=0;i<n;i++){
    if(s[i]=='('){
      S.push(i);
    }
    else{
      int j=S.top();
      S.pop();
      X[i]=j;
      X[j]=i;
    }
  }
  vector<bool> use(n,0);
  for(int i=0,t=0;t<k;i++){
    if(s[i]=='('){
      use[i]=use[X[i]]=1;
      k-=2;
    }
  }
  for(int i=0;i<n;i++){
    if(use[i]){
      putchar(s[i]);
    }
  }
  putchar('\n');
  return 0;
}