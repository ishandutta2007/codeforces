#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef long long s64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=100+5;
int n,m;
s64 x[N];int x1[N];
s64 wa,wf; 

void check(int s)
{
	int l=max(1,s-m),r=(s-1)/2;
	int limit=0;
	rep(i,1,n)
	{
		x1[i]=x[i]%s;
		chmax(limit,min(x1[i],s-x1[i]-1));
	}
	if(limit>=l)
	{
		if(limit>=r){wa+=r-l+1;return ;}
		wa+=limit-l+1;
		l=limit+1;
	}
	rep(i,1,n)x1[i]=s-x1[i];
	sort(x1+1,x1+n+1);//x1[i]<=a<x1[i+1] <=> ix'[j]>=b 
	x1[n+1]=r+1;
	wf+=max(0,min(r,x1[2]-1)-max(l,x1[1])+1);
	int limit1=(s-x1[1])/2,limit2=(s-x1[2])/2;
	//a<=limit2 <=> c2>=2
	//a<=limit1 <=> c2>=1
	rep(i,2,n)
	{
		int nl=max(l,x1[i]),nr=min(r,x1[i+1]-1);
		if(nl>nr)continue;
		if(limit2>=nl)
		{
			if(limit2>=nr){wa+=nr-nl+1;continue;}
			wa+=limit2-nl+1;nl=limit2+1;
		}
		if(i%2)wf+=nr-nl+1; 
		else wa+=max(0,min(nr,limit1)-nl+1);
	}
}
void work()
{
	rep(s,3,2*m-1)
	{
	//	s64 wa0=wa;
		check(s);
	//	cerr<<wa-wa0<<" ";
	}
	//cerr<<endl;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif	
	cin>>n>>m;
	rep(i,1,n)cin>>x[i];
	work();
	wf*=2;
	rep(a,1,m)
	{
		int c=0;
		rep(i,1,n)c^=x[i]/a%2;
		if(c==1)++wf;
	}
	cout<<wa<<" "<<wa<<" "<<wf<<" "<<(s64)m*m-wa*2-wf;
}