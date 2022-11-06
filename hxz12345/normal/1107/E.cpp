#include<bits/stdc++.h>
using namespace std;
// suf[i] si~n
// pre[i] s1_i
long long c[1000],n,a[1000],ans,x,i,j,f[220][220][220];
string s;
long long sc(int lft,int rit,int suf)
{
	 if (lft>rit) return 0;
     if (f[lft][rit][suf]!=-1) return f[lft][rit][suf];
     f[lft][rit][suf]=max(f[lft][rit][suf],sc(lft,rit-1,0)+a[suf+1]);
     for (int i=lft;i<rit;i++)
         if (c[i]==c[rit])
          f[lft][rit][suf]=max(f[lft][rit][suf],sc(lft,i,suf+1)+sc(i+1,rit-1,0));
	return f[lft][rit][suf];
}
int main()
{
	cin>>n;
		cin>>s;
	for (i=1;i<=n;i++) c[i]=s[i-1]-'0';
	for (i=1;i<=n;i++)
	     {
	     	cin>>x;
	     	for (j=i;j<=n;j++) 
	     	   a[j]=max(a[j],a[j-i]+x);
	     }
	memset(f,-1,sizeof(f));
	cout<<sc(1,n,0)<<endl;
	return 0;
}