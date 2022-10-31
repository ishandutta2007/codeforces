#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  bool c[26]={0};
  int C=26;
  int ans=0;
  char s[3],t[100010];
  for(int i=0;i<n;i++){
    scanf("%s%s",s,t);
    if(s[0]=='!'){
      if(C==1)ans++;
      else{
	bool b[26]={0};
	for(int j=0;t[j];j++){
	  b[t[j]-'a']=1;
	}
	for(int k=0;k<26;k++){
	  if(!c[k]&&!b[k]){
	    c[k]=1;
	    C--;
	  }
	}
      }
    }
    else if(s[0]=='.'){
      for(int j=0;t[j];j++){
	int k=(t[j]-'a');
	if(!c[k]){
	  c[k]=1;
	  C--;
	}
      }
    }
    else if(s[0]=='?'&&i<n-1){
      if(C==1)ans++;
      int k=t[0]-'a';
      if(!c[k]){
	c[k]=1;
	C--;
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}