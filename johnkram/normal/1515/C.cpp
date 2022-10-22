#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define L 1048576
char _buf[L],*S,*T,c,_buf1[L],*S1=_buf1;
inline char gc()
{
	if(S==T)
	{
		T=(S=_buf)+fread(_buf,1,L,stdin);
		if(S==T)return 0;
	}
	return *S++;
}
inline void pc(char c)
{
	if(S1==_buf1+L)
	{
		fwrite(_buf1,1,L,stdout);
		S1=_buf1;
	}
	*S1++=c;
}
void get(int &x)
{
	for(c=gc();(c<'0'||c>'9')&&c!='-';c=gc());
	bool b=0;
	if(c=='-')
	{
		b=1;
		c=gc();
	}
	for(x=c^'0',c=gc();c>='0'&&c<='9';c=gc())x=(x<<3)+(x<<1)+(c^'0');
	if(b)x=-x;
}
void out(int x)
{
	if(x>9)out(x/10);
	pc(x%10^'0');
}
int ask(int n)
{
	int l=1,r=30000,mid;
	while(l+1<r)
	{
		mid=l+r>>1;
		if(mid*mid<=n)l=mid;
		else r=mid;
	}
	return l;
}
struct node
{
	int s,i;
	bool operator<(const node& y)const
	{
		if(s==y.s)return i<y.i;
		return s>y.s;
	}
}t1;
priority_queue<node> h;
int t,n,m,i,a[100005],s[100005];
int main()
{
	get(t);
	while(t--)
	{
		get(n);
		get(m);
		get(i);
		pc('Y');
		pc('E');
		pc('S');
		pc('\n');
		while(!h.empty())h.pop();
		for(i=1;i<=m;i++)
		{
			t1.s=s[i]=0;
			t1.i=i;
			h.push(t1);
		}
		for(i=1;i<=n;i++)
		{
			get(a[i]);
			t1=h.top();
			h.pop();
			t1.s=s[t1.i]+=a[i];
			h.push(t1);
			out(t1.i);
			if(i==n)pc('\n');
			else pc(' ');
		}
	}
	fwrite(_buf1,1,S1-_buf1,stdout);
	return 0;
}