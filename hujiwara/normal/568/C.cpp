#include <bits/stdc++.h>
using namespace std;

bool tb[400][400]={0};
int n,m;
char s[30];

bool check(char *ans,int l)
{
  for(int i=0;i<l;i++){
    for(int j=0;j<l;j++){
      int a=i+(s[ans[i]-'a']=='V'?0:n);
      int b=j+(s[ans[j]-'a']=='V'?n:0);
      if(tb[a][b]){
	return 0;
      }
    }
  }
  return 1;
}

int main()
{
  scanf("%s",s);
  int C=strlen(s);
  int X=C,Y=-1;
  for(int i=0;i<C;i++){
    if(s[0]!=s[i]){
      X=min(X,i);
    }
    if(s[i]!=s[C-1]){
      Y=max(Y,i);
    }
  }
  scanf("%d%d",&n,&m);
  for(int i=0;i<2*n;i++){
    for(int j=0;j<2*n;j++){
      tb[i][j]=(i==j);
    }
  }
  for(int t=0;t<m;t++){
    int a,b;
    char s1[2],s2[2];
    scanf("%d%s%d%s",&a,s1,&b,s2);
    a--,b--;
    int A=a+(s1[0]=='V'?0:n),B=b+(s2[0]=='V'?0:n);
    int NA=a+(s1[0]=='V'?n:0),NB=b+(s2[0]=='V'?n:0);
    tb[A][B]=1;
    tb[NB][NA]=1;
  }
  for(int i=0;i<2*n;i++){
    for(int j=0;j<2*n;j++){
      for(int k=0;k<2*n;k++){
	tb[j][k]|=(tb[j][i]&&tb[i][k]);
      }
    }
  }
  for(int i=0;i<n;i++){
    if(tb[i][i+n]&&tb[i+n][i]){
      puts("-1");
      return 0;
    }
  }
  char word[201];
  scanf("%s",word);
  char ans[201];
  for(int i=0;i<n;i++){
    ans[i]=word[i];
  }
  int p=-1;
  if(check(ans,n)){
    p=n;
  }
  else{
    if(X==C){
      puts("-1");
      return 0;
    }
    for(int i=n-1;i>=0;i--){
      if(word[i]-'a'==C-1){
	continue;
      }
      ans[i]=word[i]+1;
      if(check(ans,i+1)){
	p=i+1;
	break;
      }
      int t=word[i]-'a'+2;
      while(t<C&&s[t]==s[word[i]-'a'+1]){
	t++;
      }
      if(t==C){
	continue;
      }
      ans[i]='a'+t;
      if(check(ans,i+1)){
	p=i+1;
	break;
      }
    }
  }
  if(p==-1){
    puts("-1");
    return 0;
  }
  bool F=0;
  for(int i=p;i<n;i++){
    ans[i]='a';
    if(!check(ans,i+1)){
      if(X==C){
	F=1;
	break;
      }
      ans[i]='a'+X;
      if(!check(ans,i+1)){
	F=1;
	break;
      }
    }
  }
  ans[n]=0;
  printf("%s\n",F?"-1":ans);
  return 0;
}