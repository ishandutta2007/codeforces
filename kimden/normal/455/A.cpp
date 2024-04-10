#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   int n,a,ans,cur,maxn;
   cin >> n;
   int cnt[100002]={};
   ll f[100001];
   for(int i=0;i<n;i++){
      cin >> a;
      maxn = max(maxn,a);
      cnt[a]++;
   }
   f[0]=0;
   f[1]=cnt[1];
   for(int i=2;i<=maxn;i++){
      f[i] = max(f[i-1],f[i-2]+cnt[i]*1LL*i);
   }
   cout << f[maxn];
   return 0;
}