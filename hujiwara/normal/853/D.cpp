#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  vector<int> a(n);
  int S=0;
  for(int i=0;i<n;i++){
    scanf("%d",&(a[i]));
    S+=a[i]/1000;
  }
  int X=10*S/11;
  X=min(X,S-a[n-1]/1000);
  bool F=0;
  for(int i=0;i<n-1;i++){
    if(a[i]==1000){
      F=1;
    }
  }
  if(!F&&(X%2==1)){
    X--;
  }
  printf("%d\n",S*1000-X*100);
  return 0;
}