#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define mid ((l+r)>>1)
#define cl (k*2)
#define cr (cl+1)
#define in (ql<=l&&qr>=r)
#define out (ql>r||qr<l)

template <typename T> inline void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> inline void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}

#define gc (c=getchar())
int read()
{
	char c;
	while(gc<'-');
	if(c=='-')
	{
		int x=gc-'0';
	    while(gc>='0')x=x*10+c-'0';
	    return -x;
	}
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}

const int N=4e4,T=N*4,K=50,U=60000;
int n,k,last[N];
int ql,qr,qx;
struct SEG
{
int ad[T],mn[T];
void add(int k,int x)
{
	ad[k]+=x;mn[k]+=x;
}
void down(int k)
{
	if(ad[k])
	{
		add(cl,ad[k]);add(cr,ad[k]);
		ad[k]=0;
	}
}
void up(int k)
{
	mn[k]=min(mn[cl],mn[cr]);
}
void add(int k,int l,int r)
{
	if(in)
	{
		add(k,1);
		return ;
	}
	if(out)return ;
	down(k);
	add(cl,l,mid);add(cr,mid+1,r);
	up(k);
}
void modify(int k,int l,int r)
{
	if(in)
	{
		mn[k]=qx;
		return ;
	}
	if(out)return ;
	down(k);
	modify(cl,l,mid);modify(cr,mid+1,r);
	up(k);
}
void modify(int x)
{
	qx=x;
	modify(1,1,n);
}
}seg[K];

int main()
{
	//freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	cin>>n>>k;
	
	rep(i,1,k-1)
	 memset(seg[i].mn,(1<<6)-1,sizeof(seg[i].mn));
	
	rep(i,1,n)
	{
		int a=read();
		
		ql=1;qr=last[a];
		if(qr)
		{
			++seg[0].mn[1];
			--qr; 
		    rep(j,1,k-1)seg[j].add(1,1,n); 
		}
		ql=qr=i;
		rep(j,1,k-1)seg[j].modify(seg[j-1].mn[1]);

		last[a]=i;
    }
    cout<<n-seg[k-1].mn[1];
}