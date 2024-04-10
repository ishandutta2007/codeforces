#include <bits/stdc++.h>
using namespace std;

const long long mod=1000000007ll;


int main()
{
  int n;
  scanf("%d",&n);
  n--;
  static char s1[1000010],s2[1000010];
  scanf("%s%s",s1,s2);
  int C[256];
  C['N']=0;
  C['E']=1;
  C['S']=2;
  C['W']=3;
  static int t1[1000000],t2[1000000];
  for(int i=0;i<n;i++){
    t1[i]=C[s1[i]];
    t2[i]=(C[s2[i]]+2)%4;
  }
  long long L4=0,R4=0,P4=1;
  long long L5=0,R5=0,P5=1;
  bool F=0;
  for(int i=n-1;i>=0;i--){
    L4=(4*L4+t1[i])%mod;
    R4=(R4+P4*t2[i])%mod;
    P4=P4*4%mod;
    L5=(5*L5+t1[i])%mod;
    R5=(R5+P5*t2[i])%mod;
    P5=P5*5%mod;
    if(L4==R4&&L5==R5){
      F=1;
      break;
    }
  }
  puts(F?"NO":"YES");
  return 0;
}