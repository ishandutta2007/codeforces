#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=2e5+5,mod=1e9+7;
typedef long long ll;
int n,a[N];
char s[N];
int ans[N];
char t[N];
int main()
{
  // freopen("1.in","r",stdin);
  scanf("%d",&n);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]);
  sort(a+1,a+1+n);
  scanf("%s",s+1);
  int l=1,r=n;
  for(int i=n;i>1;i--)
  {
    if(s[i-1]==s[i])
    {
      t[i]=((r-l+1)&1)?s[i]:(s[i]=='L'?'R':'L');
      ans[i]=a[l++];
    }
    else
    {
      ans[i]=a[r--];
      t[i]=s[i];
    }
  }
  ans[1]=a[l];
  t[1]=s[1];
  rep(i,1,n)
    printf("%d %c\n",ans[i],t[i]);
}