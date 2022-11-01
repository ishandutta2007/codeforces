#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  map<string,int> M;
  static int T[5000],I[5000],J[5000];
  static string A[5000];
  for(int t=0;t<n;t++){
    string s,temp,a;
    cin>>s>>temp>>a;
    M[s]=t;
    if(a[0]=='0'||a[0]=='1'){
      T[t]=0;
      A[t]=a;
    }
    else{
      string b,c;
      cin>>b>>c;
      T[t]=(b=="AND"?1:b=="OR"?2:3);
      I[t]=(a=="?"?-1:M[a]);
      J[t]=(c=="?"?-1:M[c]);
    }
    //printf("%d %d %d %d\n",t,T[t],I[t],J[t]);
  }
  char ans1[1010],ans2[1010];
  for(int i=0;i<m;i++){
    int g0=0,g1=0;
    bool A0[5000],A1[5000];
    for(int t=0;t<n;t++){
      if(T[t]==0){
	A0[t]=A1[t]=(A[t][i]=='1');
      }
      else{
	bool a0=(I[t]==-1?0:A0[I[t]]);
	bool b0=(J[t]==-1?0:A0[J[t]]);
	bool a1=(I[t]==-1?1:A1[I[t]]);
	bool b1=(J[t]==-1?1:A1[J[t]]);
	A0[t]=(T[t]==1?a0&b0:T[t]==2?a0|b0:a0^b0);
	A1[t]=(T[t]==1?a1&b1:T[t]==2?a1|b1:a1^b1);
      }
      g0+=A0[t];
      g1+=A1[t];
    }
    //printf("%d %d\n",g0,g1);
    ans1[i]=(g0<=g1?'0':'1');
    ans2[i]=(g0>=g1?'0':'1');
  }
  ans1[m]=ans2[m]=0;
  printf("%s\n%s\n",ans1,ans2);
  return 0;
}