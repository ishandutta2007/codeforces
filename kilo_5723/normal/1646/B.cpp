#include <cstdio>
#include <iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
const int maxn=2e5+5;
int a[maxn];

int main() {
  int tt;
  scanf("%d",&tt);
  while (tt--){
    int n;scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);reverse(a,a+n);
    int m=(n-1)/2,k=m+1;
    ll sum1=0,sum2=0;
    for (int i=0;i<m;i++) sum1+=a[i];
    for (int i=n-k;i<n;i++) sum2+=a[i];
    puts(sum1>sum2?"YES":"NO");
  }
  return 0;
}