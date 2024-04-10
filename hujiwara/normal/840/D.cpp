#include <bits/stdc++.h>
using namespace std;

int mrand()
{
  return (rand()<<15)+rand();
}

int main()
{
  int n,q;
  scanf("%d%d",&n,&q);
  vector<int> a(n);
  for(int i=0;i<n;i++){
    scanf("%d",&(a[i]));
    a[i]--;
  }
  vector<vector<int> > p(n);
  for(int i=0;i<n;i++){
    p[a[i]].push_back(i);
  }
  const int X=60;
  int rd[X];
  for(int t=0;t<X;t++){
    rd[t]=mrand();
  }
  while(q--){
    int l,r,k;
    scanf("%d%d%d",&l,&r,&k);
    l--;
    int s=(r-l)/k;
    int x=-1;
    for(int t=0;t<X;t++){
      int c=a[l+rd[t]%(r-l)];
      int d=lower_bound(p[c].begin(),p[c].end(),l)-p[c].begin();
      if(d+s<p[c].size()&&p[c][d+s]<r&&(x==-1||x>c+1)){
	x=c+1;
      }
    }
    printf("%d\n",x);
  }
  return 0;
}