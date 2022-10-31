#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  vector<int> a(n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  static bool E[4000]={0};
  int ans=n;
  for(int p=2;p<4000;p++){
    if(E[p])continue;
    for(int i=2*p;i<4000;i+=p){
      E[i]=1;
    }
    int m=1000,c=n;
    for(int i=0;i<n;i++){
      int ct=0;
      while(a[i]%p==0){
	a[i]/=p;
	ct++;
      }
      if(m>ct){
	m=ct;
	c=1;
      }
      else if(m==ct){
	c++;
      }
    }
    ans=min(ans,c);
  }
  sort(a.begin(),a.end());
  for(int i=0;i<n;){
    int t=1;
    while(i+t<n&&a[i]==a[i+t]){
      t++;
    }
    if(a[i]>1&&t<n){
      ans=min(ans,n-t);
    }
    i+=t;
  }
  printf("%d\n",ans==n?-1:ans);
  return 0;
}