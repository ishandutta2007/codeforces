#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  vector<int> c(n);
  for(int i=0;i<n;i++){
    scanf("%d",&(c[i]));
  }
  priority_queue<pair<int,int> > Q;
  long long ct=0ll;
  vector<int> ans(n);
  for(int t=0;t<k;t++){
    Q.push(make_pair(c[t],t));
  }
  for(int t=k;t<n+k;t++){
    if(t<n){
      Q.push(make_pair(c[t],t));
    }
    int i=Q.top().second;
    Q.pop();
    ans[i]=t;
    ct+=(long long)c[i]*(t-i);
  }
  printf("%lld\n",ct);
  for(int i=0;i<n;i++){
    printf("%d ",ans[i]+1);
  }
  putchar('\n');
  return 0;
}