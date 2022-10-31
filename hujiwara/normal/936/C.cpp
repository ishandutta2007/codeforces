#include <bits/stdc++.h>
using namespace std;

int n;
int S[2100];
vector<int> ans;

void op(int x)
{
  ans.push_back(x);
  int T[2100];
  for(int i=0;i<n;i++){
    T[i]=S[i];
  }
  for(int i=0;i<x;i++){
    S[i]=T[n-i-1];
  }
  for(int i=x;i<n;i++){
    S[i]=T[i-x];
  }
}

int main()
{
  char s[2100],t[2100];
  scanf("%d%s%s",&n,s,t);
  vector<int> pt[26];
  for(int i=0;i<n;i++){
    pt[t[i]-'a'].push_back(i);
  }
  int ct[26]={0};
  bool F=0;
  for(int i=0;i<n;i++){
    int c=s[i]-'a';
    if(ct[c]>=pt[c].size()){
      F=1;
      break;
    }
    S[i]=pt[c][ct[c]];
    ct[c]++;
  }
  if(F){
    puts("-1");
    return 0;
  }
  for(int i=0;i<n-1;i++){
    int a=i+1,b=i;
    int A,B;
    for(int i=0;i<n;i++){
      if(S[i]==a){
	A=i;
      }
      if(S[i]==b){
	B=i;
      }
    }
    if(A>B){
      if(A<n-1){
	op(n-A-1);
      }
      op(n);
    }
    else{
      op(n-A-1);
      op(1);
    }
    for(int i=0;i<n;i++){
      if(S[i]==b){
	B=i;
      }
    }
    op(n-B);
  }
  printf("%d\n",(int)ans.size());
  for(int i=0;i<ans.size();i++){
    printf("%d%c",ans[i],i+1==ans.size()?'\n':' ');
  }
  return 0;
}