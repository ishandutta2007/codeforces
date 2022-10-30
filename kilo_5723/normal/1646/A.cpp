#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  int tt;
  scanf("%d",&tt);
  while (tt--){
    ll n,s;
    scanf("%lld%lld",&n,&s);
    printf("%lld\n",s/n/n);
  }
  return 0;
}