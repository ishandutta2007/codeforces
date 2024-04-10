#include <cstdio>
#include <iostream>
#include <vector>

using  namespace std;

int n;
string s[100000],S;
int T[300000];
vector<int> e[100000];

int KMP(int j,int i)
{
  int c=0,k=0;
  while(k<s[i].size()){
    if(S[j]==s[i][k]){
      j++;
      if(j==S.size()){
	c++;
	j=T[j-1];
      }
      k++;
    }
    else if(j>0){
      j=T[j-1];
    }
    else{
      k++;
    }
  }
  for(int k=0;k<e[i].size();k++){
    c+=KMP(j,e[i][k]);
  }
  return c;
}

int main()
{
  scanf("%d",&n);
  for(int i=1;i<n;i++){
    int j;
    scanf("%d",&j);
    j--;
    e[j].push_back(i);
    cin>>s[i];
  }
  cin>>S;
  T[0]=0;
  for(int i=1,j=0;i<=S.size();){
    if(S[j]==S[i]){
      T[i]=j+1;
      j++;
      i++;
    }
    else if(j>0){
      j=T[j-1];
    }
    else{
      T[i]=0;
      i++;
    }
  }
  printf("%d\n",KMP(0,0));
  return 0;
}