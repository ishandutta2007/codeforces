#include <bits/stdc++.h>
using namespace std;
const int MN=400000;
const long long mod=1000000007ll;
int main()
{
  int n;
  scanf("%d",&n);
  static int T[MN],p[MN],X[MN];
  for(int i=0;i<n;i++){
    char s[100];
    scanf("%s%d",s,p+i);
    X[i]=p[i];
    T[i]=(s[1]=='D');
  }
  sort(X,X+n);
  static int D[MN]={0};
  set<int> S;
  S.insert(0);
  long long ans=1ll;
  int t=1,now=1;
  D[0]=1;
  for(int i=0;i<n;i++){
    int j=lower_bound(X,X+n,p[i])-X+1;
    if(T[i]==1){
      auto it=S.upper_bound(j);
      it--;
      int k=*it;
      S.insert(j);
      if(D[k]==now){
	D[j]=now;
	t++;
      }
    }
    else{
      auto it=S.find(j);
      it--;
      int k=*it;
      S.erase(j);
      if(D[k]!=now&&D[j]!=now){
	ans=0ll;
	break;
      }
      if(D[k]==now&&D[j]==now){
	ans=2*ans%mod;
      }
      D[k]=now+1;
      now++;
      t=1;
    }
  }
  printf("%lld\n",ans*t%mod);
  return 0;
}