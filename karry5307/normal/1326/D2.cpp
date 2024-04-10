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
const ll MAXN=1e6+51,MOD=998244353,inf=0x3f3f3f3f;
// Structures and variables
ll test,p,q,l,r;
string str;
ll hsh[MAXN],hsh2[MAXN],pw[MAXN];
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
// Functions
inline ll getHash(ll l,ll r)
{
	return (hsh[r]+MOD-(li)(l==0?0:hsh[l-1])*pw[r-l+1]%MOD)%MOD;
}
inline ll getHash2(ll l,ll r)
{
	return (hsh2[l]+MOD-(li)hsh2[r+1]*pw[r-l+1]%MOD)%MOD;
}
inline bool check(ll l,ll r)
{
	return getHash(l,r)==getHash2(l,r);
}
inline void solve()
{
	cin>>str,p=0,q=str.length()-1,l=0;
	hsh[0]=str[0]-'a'+1,hsh2[q]=str[q]-'a'+1,hsh2[q+1]=0;
	while(str[p]==str[q]&&q>=0)
	{
		p++,q--;
	}
	if(q==-1)
	{
		cout<<str<<endl;
		return;
	}
	for(register int i=1;i<str.length();i++)
	{
		hsh[i]=((li)hsh[i-1]*19491001+(str[i]-'a'+1))%MOD;
	}
	for(register int i=str.length()-2;i>=0;i--)
	{
		hsh2[i]=((li)hsh2[i+1]*19491001+(str[i]-'a'+1))%MOD;
	}
	for(register int i=q;i>=p;i--)
	{
		if(check(p,i))
		{
			l=p,r=i;
			break;
		}
	}
	for(register int i=p;i<=q;i++)
	{
		if(check(i,q))
		{
			if(q-i>=r-l)
			{
				l=i,r=q;
			}
			break;
		}
	}
	for(register int i=0;i<p;i++)
	{
		putchar(str[i]);
	}
	for(register int i=l;i<=r;i++)
	{
		putchar(str[i]);
	}
	for(register int i=q+1;i<str.length();i++)
	{
		putchar(str[i]);
	}
	puts("");
}
int main()
{
	test=read(),pw[0]=1;
	for(register int i=1;i<1000001;i++)
	{
		pw[i]=(li)pw[i-1]*19491001%MOD;
	}
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}