#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,m,i,j,pre[300005],p0[300005],p2[300005],p3[300005],s0[300005],s2[300005];
int ans,sl,sr,bse;
stack<int> stk;
string st;

int f(int x,int b)
{
	x+=b;
	if(x>n) x-=n;
	return x;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>st;st=" "+st; 
	
	int mi=1;
	rep(i,n)
	{
		pre[i]=pre[i-1]+(st[i]=='('?1:-1);
		if (pre[i]<pre[mi]) mi=i;
	}
	if (pre[n]!=0)
	{
		cout<<"0\n1 1\n";
		return 0;
	}
	
	rep(i,n)
	{
		pre[i]=pre[i-1]+(st[f(i,mi)]=='('?1:-1);
		if(!pre[i]) bse++;
	}
	sl=sr=1;ans=bse;
	
	rep(i,n)
	{
		p0[i]=p0[i-1];p2[i]=p2[i-1];p3[i]=p3[i-1];
		if (pre[i]==2&&st[f(i,mi)]==')') p3[i]++;
		if (pre[i]==1&&st[f(i,mi)]==')') p2[i]++;
		if (pre[i]==0&&st[f(i,mi)]==')') p0[i]++;
	}
	per(i,n)
	{
		s0[i]=s0[i+1];s2[i]=s2[i+1];
		if (pre[i]==1&&st[f(i,mi)]==')') s2[i]++;
		if (pre[i]==0&&st[f(i,mi)]==')') s0[i]++;
	}
	
	rep(i,n)
	{
		if (st[f(i,mi)]=='(') stk.push(i);
		else
		{
			int l=stk.top(),r=i;
			stk.pop();
			int s;
			if(stk.size()==0) s=bse+(p2[r]-p2[l-1])-(p0[l-1]+s0[r+1]);
			else if(stk.size()==1) s=bse+(p3[r]-p3[l-1])+1;
			else continue;
			if (s>ans)
			{
				ans=s;
				sl=f(l,mi);
				sr=f(r,mi);
			}
		}
	}
	
	cout<<ans<<endl<<sl<<' '<<sr<<endl;
	
	return 0;
}