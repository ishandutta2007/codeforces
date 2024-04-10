// This code is written by Karry5307
#include<bits/stdc++.h>
// Definition
#define For(i,x,y) for(register int i=(x);i<(y);i++)
#define Forr(i,x,y) for(register int i=(x);i<=(y);i++)
#define Rep(i,x,y) for(register int i=(x);i>(y);i--)
#define Repp(i,x,y) for(register int i=(x);i>=(y);i--)
#define ve vector
#define iter iterator
#define pb emplace_back
#define popb pop_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define F first
#define S second
using namespace std;
// Typedefs
typedef int ll;
typedef long long int li;
typedef unsigned int ul;
typedef unsigned long long int ull;
typedef double db;
typedef long double ldb;
typedef pair<ll,ll> pii;
typedef pair<li,li> pll;
const ll MAXN=251,MOD=998244353,inf=0x3f3f3f3f;
// Structures and variables
ll test,n,pos,sum,pp;
string str;
vector<ll>v,v2;
ll x[MAXN],rk[MAXN],occ[MAXN],rs[MAXN];
char res[MAXN],rx[MAXN];
// Fast IO
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-') ch=getchar();
    if(ch=='-') neg=-1,ch=getchar();
    while(isdigit(ch)) num=(num<<3)+(num<<1)+(ch-'0'),ch=getchar();
    return neg==1?num:-num;
} 
inline li readu()
{
    register li num=0;
    register char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) num=(num<<3)+(num<<1)+(ch-'0'),ch=getchar();
    return num;
} 
template<class T>
inline void writep(T x)
{
	if(x<0){return (void)putchar('-'),writep(-x);}
	if(x<10){return (void)putchar(x|48);}
	writep(x/10),putchar((x%10)|48);
}
template<class T>
inline void write(T x,char ch=' '){writep(x),putchar(ch);}
template<class T>
inline void writeln(T x){writep(x),putchar('\n');}
// chkmin and chkmax
template<class T>
inline void chkmax(T &x,const T &y){x=x>y?x:y;}
template<class T>
inline void chkmin(T &x,const T &y){x=x<y?x:y;}
// Functions
template<class T,class Compare>
inline void sort(ve<T>&v,Compare cmp=less<T>()){sort(all(v),cmp);}
template<class T>
inline void reverse(ve<T>&v){reverse(all(v));}
template<class T>
inline void clear(T *arr){memset(arr,0,sizeof(arr));}
template<class T>
inline void setInf(T *arr){memset(arr,0x3f,sizeof(arr));}
// Math funcs
inline ll qpow(ll base,ll exponent)
{
	li res=1;
	while(exponent)
	{
		if(exponent&1)
		{
			res=(li)res*base%MOD;
		}
		base=(li)base*base%MOD,exponent>>=1;
	}
	return res;
}
inline ll gcd(ll x,ll y)
{
	return !y?x:gcd(y,x%y);
}
inline li lcm(ll x,ll y)
{
	return x/gcd(x,y)*y;
}
// Functions
inline ll calc(ll x)
{
	ll res=0;
	for(register int i=0;i<v.size();i++)
	{
		res+=abs(v[i]-x);
	}
	return res;
}
inline void solve()
{
	cin>>str,n=read(),memset(rk,0,sizeof(rk)),memset(occ,0,sizeof(occ));
	memset(rs,0,sizeof(rs)),memset(rx,0,sizeof(rx)),memset(res,0,sizeof(res));
	v.clear(),sum=0,pp=1;
	for(register int i=0;i<str.length();i++)
	{
		occ[str[i]-'a']++;
	}
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
		if(!x[i])
		{
			rk[i]=1,v.push_back(i),sum++,rs[1]++;
		}
	}
	while(sum!=n)
	{
		pp++,v2.clear();
		for(register int i=1;i<=n;i++)
		{
			if(!rk[i]&&calc(i)==x[i])
			{
				v2.push_back(i),rk[i]=pp,sum++,rs[pp]++;
			}
		}
		for(register int i=0;i<v2.size();i++)
		{
			v.push_back(v2[i]);
		}
	}
	for(register int i=1,j=25;i<=n;i++)
	{
		while(occ[j]<rs[i])
		{
			j--;
		}
		rx[i]=j+'a',j--;
	}
	for(register int i=1;i<=n;i++)
	{
		res[i]=rx[rk[i]];
	}
	printf("%s\n",res+1);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}