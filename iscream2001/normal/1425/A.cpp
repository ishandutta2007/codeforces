#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define IL inline
#define rep(i,h,t) for (rint i=h;i<=t;i++)
#define dep(i,t,h) for (rint i=t;i>=h;i--)
#define mid ((h+t)>>1)
#define ll long long
ll n;
ll cl(ll n)
{
	if (n==0) return 0;
	if (n==1) return 1;
	if (n==4) return 3;
	if (n%2==1) return n-cl(n-1);
	if ((n/2)%2==1) return cl((n/2)-1)+(n/2);
	else return cl(n-2)+1; 
}
int main()
{
  ios::sync_with_stdio(false);
  int T;
  cin>>T;
  while (T--)
  {
  	 cin>>n;
  	 cout<<cl(n)<<endl;
  }
  return 0; 
}