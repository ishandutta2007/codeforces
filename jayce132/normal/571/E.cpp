#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define ll long long
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=1e5+20;
const int mod=1e9+7;

inline ll power(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return ans;
}


//#define ll long long
int n;

#define pii pair<ll,ll>

unordered_map<int,pii>A,B;
unordered_map<int,pii>::iterator it;
int sx[maxn],tx;

inline void fj(int x,int op,unordered_map<int,pii> &mp)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
		{
			int s=0;
			while(!(x%i))x/=i,s++;
			if(op==0)mp[i].fi+=s;
			else mp[i].se+=s;
			
		}
	if(x>1)
	{
		if(op==0)mp[x].fi++;
		else mp[x].se++;
	}
}

inline void exgcd(ll a,ll &x,ll b,ll &y)
{
	return !b?(x=1,y=0,void()):(exgcd(b,y,a%b,x),y-=(a/b)*x,void());
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("571E.in","r",stdin);
	freopen("571E.out","w",stdout);
#endif
	n=read();
	int a=read(),b=read();
	fj(a,0,A); fj(b,1,A);
	tx=0;
	for(it=A.begin();it!=A.end();it++)sx[++tx]=it->fi;
	sort(sx+1,sx+tx+1); tx=unique(sx+1,sx+tx+1)-sx-1;
	REP(i,2,n)
	{
		B.clear();
		int c=read(),d=read();
		fj(c,0,B); fj(d,1,B);
		tx=0;
		for(it=A.begin();it!=A.end();it++)sx[++tx]=it->fi;
		for(it=B.begin();it!=B.end();it++)sx[++tx]=it->fi;
		sort(sx+1,sx+tx+1); tx=unique(sx+1,sx+tx+1)-sx-1;
		int st;
		REP(j,1,tx)
		{
			int x=sx[j];
			if(!A[x].se && !B[x].se)
			{
				if(A[x].fi==B[x].fi);
				else puts("-1"),exit(0);
			}else { st=j;break;}
		}
		int flg=st;
		REP(j,st+1,tx)
		{
			int x=sx[st],y=sx[j];
			if(A[x].se*B[y].se==A[y].se*B[x].se && (A[x].fi-B[x].fi)*B[y].se==(A[y].fi-B[y].fi)*B[x].se);
			else {flg=j;break;}
		}

		
		
		if(flg==st)
		{
			ll t1=sx[st];
			ll a=A[t1].se,b=-B[t1].se,c=B[t1].fi-A[t1].fi;
			if(!a && !b && !c)continue;
			ll g=__gcd(__gcd(a,b),c) ;
			if(g<0)g=-g;
			a/=g; b/=g; c/=g;
			g=__gcd(a,b);
			if(g<0)g=-g;
			if(g>1)puts("-1"),exit(0);
			ll x,y;
			exgcd(a,x,b,y);
			ll val=a*x+b*y,remc=c;
			if(c<0)c=-c,x=-x,y=-y;
			//x*=c/val; y*=c/val;
			x/=val; y/=val;
			b=-b; 
			ll plus,prod;
			if(c==0)plus=0,prod=b;
			else if(a==0 && y<0 || b==0 && x<0)puts("-1"),exit(0);
			else if(a==0)plus=0,prod=0;
			else if(b==0)plus=x,prod=0;
			else {
				x=x*c%b;
				x=(x+b)%b; y=(a*x-remc)/b;
                ll t=min((x/b),(y/a));
				x-=t*b; y-=a*t;
				while(x<0 || y<0)x+=b,y+=a;
				while(x>=b && y>=a)x-=b,y-=a;
				
				//assert(a*x-b*y==1);
				plus=x,prod=b;
			}
			REP(i,1,tx)A[sx[i]].fi+=A[sx[i]].se*plus,A[sx[i]].se*=prod;
		}else
		{
			ll t1=sx[st],t2=sx[flg];
			ll a=A[t1].se,b=B[t1].se,c=B[t1].fi-A[t1].fi; ll d=A[t2].se,e=B[t2].se,f=B[t2].fi-A[t2].fi;
			ll cs=b*d-a*e,X=b*f-c*e,Y=a*f-c*d;
			if(cs && X%cs==0 && Y%cs==0)
			{
				X/=cs; Y/=cs;
				if(X>=0 && Y>=0);
				else puts("-1"),exit(0);
			}else puts("-1"),exit(0);
			REP(i,1,tx)
			{
				ll a=A[sx[i]].se,b=A[sx[i]].fi,c=B[sx[i]].se,d=B[sx[i]].fi;
				if(a*X+b!=c*Y+d)puts("-1"),exit(0);
				else A[sx[i]].fi=a*X+b,A[sx[i]].se=0;
			}
		}
	}

	int ans=1;
	REP(i,1,tx)
	{
		ans=(ll)ans*power(sx[i],A[sx[i]].fi)%mod;
	}
	printf("%d\n",ans);
	return 0;
}