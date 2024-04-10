#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  int id[1000],X[1000];
  for(int i=0;i<n;i++){
    scanf("%d",id+i);
    X[i]=id[i];
  }
  sort(X,X+n);
  int L[1000]={0};
  for(int i=0;i<n;i++){
    if(id[i]>0){
      int a=lower_bound(X,X+n,id[i])-X;
      L[a]++;
    }
  }
  int k=0;
  bool b=0;
  for(int i=0;i<n;i++){
    if(L[i]==2){
      k++;
    }
    else if(L[i]>2){
      b=1;
      break;
    }
  }
  printf("%d\n",b?-1:k);
  return 0;
}