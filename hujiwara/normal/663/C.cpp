#include <bits/stdc++.h>
using namespace std;

int rt(int *uf,int i)
{
  return uf[i]<0?i:uf[i]=rt(uf,uf[i]);
}

void con(int *uf,int *s1,int a,int b)
{
  if(a!=b){
    if(-uf[a]<-uf[b]){
      uf[a]=b;
      s1[b]+=s1[a];
    }
    else if(-uf[a]>-uf[b]){
      uf[b]=a;
      s1[a]+=s1[b];
    }
    else{
      uf[a]=b;
      s1[b]+=s1[a];
      uf[b]--;
    }
  }
}


int main()
{
  int  n,m;
  scanf("%d%d",&n,&m);
  static int A[100000],B[100000],C[100000];
  for(int i=0;i<m;i++){
    char s[2];
    scanf("%d%d%s",A+i,B+i,s);
    A[i]--,B[i]--;
    C[i]=(s[0]=='R');
  }
  bool F=0;
  vector<int> ans;
  for(int t=0;t<2;t++){
    bool G=1;
    static int uf[200000],S[200000];
    for(int i=0;i<2*n;i++){
      uf[i]=-1;
      S[i]=(i<n?1:0);
    }
    for(int i=0;i<m;i++){
      int a=A[i],b=B[i];
      int r1=rt(uf,a),r2=rt(uf,b),r3=rt(uf,a+n),r4=rt(uf,b+n);
      //printf("%d %d %d %d %d\n",C[i],r1,r2,r3,r4);
      if(C[i]==t){
	if(r1==r4||r2==r3){
	  G=0;
	  goto NO;
	}
	else{
	  con(uf,S,r1,r2);
	  con(uf,S,r3,r4);
	}
      }
      else{
	if(r1==r2||r3==r4){
	  G=0;
	  goto NO;
	}
	else{
	  con(uf,S,r1,r4);
	  con(uf,S,r2,r3);
	}
      }
    }
  NO:if(!G)continue;
    vector<int> an;
    for(int i=0;i<n;i++){
      int r1=rt(uf,i),r2=rt(uf,i+n);
      //printf("%d %d %d\n",i,r1,r2);
      if(S[r1]<S[r2]||(S[r1]==S[r2]&&r1<r2)){
	an.push_back(i);
      }
    }
    if(!F||ans.size()>an.size()){
      ans=an;
      F=1;
    }
  }
  if(!F){
    puts("-1");
  }
  else{
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++){
      printf("%d%c",ans[i]+1,i<ans.size()-1?' ':'\n');
    }
  }
  return 0;
}