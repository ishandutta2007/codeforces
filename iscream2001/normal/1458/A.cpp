#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
#define me(x) memset(x,0,sizeof(x))
#define IL inline
#define rint register int
char ss[1<<24],*A=ss,*B=ss;
IL char gc()
{
	return A==B&&(B=(A=ss)+fread(ss,1,1<<24,stdin),A==B)?EOF:*A++;
}
template<class T>void read(T &x)
{
	int f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=(c^48);
	while(c=gc(),c>47&&c<58) x=x*10+(c^48); x*=f;
}
const int mo=1e9+7;
struct re{
	int a,b,c;
};
int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
const int N=3e5;
ll a[N],b[N]; 
int n,m;
int main()
{
   ios::sync_with_stdio(false);
   cin>>n>>m;
   rep(i,1,n) cin>>a[i];
   rep(i,1,m) cin>>b[i];
   ll k=0;
   rep(i,1,n-1)
   {
   	 k=gcd(k,a[i+1]-a[i]);
   }
   ll k2=k;
   rep(i,1,m)
   {
     cout<<gcd(k,a[1]+b[i])<<" ";
   }
   return 0;
}