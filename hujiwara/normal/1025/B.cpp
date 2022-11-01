#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++){
    scanf("%d%d",&a[i],&b[i]);
  }
  vector<int> d;
  for(int t=0;t<2;t++){
    int A=(t==0?a[0]:b[0]);
    for(int i=2;(long long)i*i<=A;i++){
      if(A%i==0){
	d.push_back(i);
	while(A%i==0){
	  A/=i;
	}
      }
    }
    if(A>1){
      d.push_back(A);
    }
  }
  sort(d.begin(),d.end());
  d.erase(unique(d.begin(),d.end()),d.end());
  int ans=-1;
  for(int t=0;t<d.size();t++){
    int p=d[t];
    bool G=1;
    for(int i=1;i<n;i++){
      if(a[i]%p!=0&&b[i]%p!=0){
	G=0;
	break;
      }
    }
    if(G){
      ans=p;
      break;
    }
  }
  printf("%d\n",ans);
  return 0;
}