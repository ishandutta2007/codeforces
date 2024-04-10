#include <bits/stdc++.h>
using namespace std;

int main()
{
  static char s[200010],p[200010];
  scanf("%s%s",s,p);
  int n=strlen(s);
  static int a[200010];
  for(int i=0;i<n;i++){
    scanf("%d",a+i);
    a[i]--;
  }
  static int b[200010];
  for(int i=0;i<n;i++){
    b[a[i]]=i;
  }
  int P=strlen(p);
  /*static int T[200010];
  T[0]=-1,T[1]=0;
  for(int i=2,j=0;i<P;){
    if(s[i-1]==s[j]){
      T[i]=j+1;
      i++;
      j++;
    }
    else if(j>0){
      j=T[j];
    }
    else{
      T[i]=0;
      i++;
    }
    }*/
  int L=0,R=n;
  while(L+1<R){
    int d=(L+R)/2;
    char q[200010];
    int m=0;
    for(int i=0;i<n;i++){
      if(b[i]>=d){
	q[m]=s[i];
	m++;
      }
    }
    q[m]=0;
    //printf("%d %s\n",d,q);
    int l=0;
    for(int k=0;k<m;k++){
      if(l<P&&p[l]==q[k]){
	l++;
      }
    }
    if(l==P){
      L=d;
    }
    else{
      R=d;
    }
  }
  printf("%d\n",L);
  return 0;
}