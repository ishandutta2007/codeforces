#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 2e6 + 5;
int a[maxn];
int b[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, c;
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    fill(b,b+2*c+1,maxn);
    for (int i=0;i<n;i++) b[a[i]]=0;
    for (int i=1;i<=2*c;i++) b[i]=min(b[i],b[i-1]+1);
    bool flg=true;
    for (int i=1;i<=c;i++) if (b[i]!=0)
      for (int j=1;j<=c/i;j++) if (b[j]==0){
        if (b[i*j+j-1]<j){
          // cout<<i<<' '<<j<<endl;
          flg=false;
        }
      }
    puts(flg?"Yes":"No");
  }
  return 0;
}