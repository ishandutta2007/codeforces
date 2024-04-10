#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  long long A=(long long)n;
  for(int i=0;i<n;i++){
    int a;
    scanf("%d",&a);
    A+=(long long)(a-1LL)*(i+1);
  }
  cout<<A<<'\n';
  return 0;
}