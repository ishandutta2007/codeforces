#include <bits/stdc++.h>
using namespace std;

const int IN=0,NOT=1,AND=2,OR=3,XOR=4;

int n;
vector<int> type,c1,c2,val,val2;

void dfs1(int i)
{
  if(type[i]==IN){
    val[i]=c1[i];
  }
  else if(type[i]==NOT){
    dfs1(c1[i]);
    val[i]=!val[c1[i]];
  }
  else if(type[i]==AND){
    dfs1(c1[i]);
    dfs1(c2[i]);
    val[i]=(val[c1[i]]&&val[c2[i]]);
  }
  else if(type[i]==OR){
    dfs1(c1[i]);
    dfs1(c2[i]);
    val[i]=(val[c1[i]]||val[c2[i]]);
  }
  else if(type[i]==XOR){
    dfs1(c1[i]);
    dfs1(c2[i]);
    val[i]=(val[c1[i]]^val[c2[i]]);
  }
}

void dfs2(int i)
{
  if(type[i]==NOT){
    val2[c1[i]]=val2[i];
    dfs2(c1[i]);
  }
  else if(type[i]==AND){
    val2[c1[i]]=(val[c2[i]]?val2[i]:val[0]);
    val2[c2[i]]=(val[c1[i]]?val2[i]:val[0]);
    dfs2(c1[i]);
    dfs2(c2[i]);
  }
  else if(type[i]==OR){
    val2[c1[i]]=(!val[c2[i]]?val2[i]:val[0]);
    val2[c2[i]]=(!val[c1[i]]?val2[i]:val[0]);
    dfs2(c1[i]);
    dfs2(c2[i]);
  }
  else if(type[i]==XOR){
    val2[c1[i]]=val2[i];
    val2[c2[i]]=val2[i];
    dfs2(c1[i]);
    dfs2(c2[i]);
  }
  //printf("%d %d %d\n",i+1,val[i],val2[i]);
}

int main()
{
  scanf("%d",&n);
  type=vector<int>(n);
  c1=vector<int>(n);
  c2=vector<int>(n);
  val=vector<int>(n);
  val2=vector<int>(n);
  for(int i=0;i<n;i++){
    char s[10];
    scanf("%s",s);
    if(s[0]=='I'){
      type[i]=IN;
      scanf("%d",&(c1[i]));
    }
    else if(s[0]=='N'){
      type[i]=NOT;
      scanf("%d",&c1[i]);
      c1[i]--;
    }
    else{
      type[i]=(s[0]=='A'?AND:s[0]=='O'?OR:XOR);
      scanf("%d%d",&c1[i],&c2[i]);
      c1[i]--,c2[i]--;
    }
  }
  dfs1(0);
  val2[0]=!val[0];
  dfs2(0);
  for(int i=0;i<n;i++){
    if(type[i]==IN){
      putchar('0'+val2[i]);
    }
  }
  putchar('\n');
  return 0;
}