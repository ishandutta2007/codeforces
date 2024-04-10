#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b)
{
  return b==0?a:gcd(b,a%b);
}

int main()
{
  int n;
  scanf("%d",&n);
  vector<long long> a(n);
  for(int i=0;i<n;i++){
    scanf("%lld",&a[i]);
  }
  vector<vector<bool> > g(n,vector<bool>(n));
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      g[i][j]=(gcd(a[i],a[j])>1ll);
    }
  }
  vector<vector<bool> > dpl(n,vector<bool>(n)),dpr(n,vector<bool>(n));
  for(int i=0;i<n;i++){
    dpl[i][i]=dpr[i][i]=true;
  }
  for(int t=1;t<n;t++){
    for(int i=0;i+t<n;i++){
      int j=i+t;
      dpl[i][j]=false;
      for(int k=i+1;k<=j;k++){
	if(g[i][k]&&dpr[i+1][k]&&dpl[k][j]){
	  dpl[i][j]=true;
	}
      }
      dpr[i][j]=false;
      for(int k=i;k<j;k++){
	if(g[k][j]&&dpr[i][k]&&dpl[k][j-1]){
	  dpr[i][j]=true;
	}
      }
      //printf("%d %d %d %d\n",i,j,(int)dpl[i][j],(int)dpr[i][j]);
    }
  }
  bool ans=false;
  for(int i=0;i<n;i++){
    if(dpr[0][i]&&dpl[i][n-1]){
      ans=true;
    }
  }
  puts(ans?"Yes":"No");
  return 0;
}