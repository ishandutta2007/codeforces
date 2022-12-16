#include<bits/stdc++.h>
using namespace std;
const int N=500005,M=1000000007;
namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed integer
	template <class I>
	inline void gi (I &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	// print a signed integer
	template <class I>
	inline void print (I x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi;
using io :: putc;
using io :: print;
int n,m,i,num;
struct str{
	long long x,y;
}a[N];
long long ans,s,ts,sum,as,sx,sy;
str operator -(str a,str b)
{
	return (str){a.x-b.x,a.y-b.y};
}
long long mult(str a,str b)
{
	return a.x*b.y-a.y*b.x;
}
int main()
{
	gi(n);
	for(i=1;i<=n;++i)
		gi(a[i].x),gi(a[i].y);
	if(n<=3)
	{
		puts("0");
		return 0;
	}
	for(i=2;i<n;++i)
		ans+=mult(a[i+1]-a[1],a[i]-a[1]);
	int l=n;
	unsigned long long s=0;
	sx=a[l].x,sy=a[l].y;
	while((s+mult(a[l]-a[1],a[l-1]-a[1]))*2<=ans)
	{
		s+=mult(a[l]-a[1],a[l-1]-a[1]);
		ts=(ts+a[l].x*a[l-1].y-a[l].y*a[l-1].x)%M;
		sx=(sx+a[l-1].x)%M;
		sy=(sy+a[l-1].y)%M;
		sum=(sum+ts)%M;
		++num;
		--l;
	}
	as=(as+sum+(sx-a[n].x*(num+1))*a[1].y-(sy-a[n].y*(num+1))*a[1].x)%M;
	for(i=2;i<=n;++i)
	{
		s+=mult(a[i]-a[l],a[i-1]-a[l]);
		ts=(ts+a[i-1].x*a[(i==2?n:i-2)].y-a[i-1].y*a[(i==2?n:i-2)].x)%M;
		sx=(sx+a[i-1].x)%M;
		sy=(sy+a[i-1].y)%M;
		++num;
		sum=(sum+(a[i-1].x*a[(i==2?n:i-2)].y-a[i-1].y*a[(i==2?n:i-2)].x)%M*num)%M;
		while(s*2>ans||(s*2==ans&&i>l))
		{
			sum=(sum-ts)%M;
			sx=(sx-a[l].x)%M;
			sy=(sy-a[l].y)%M;
			ts=(ts-a[l%n+1].x*a[l].y%M+a[l%n+1].y*a[l].x%M)%M;
			s-=mult(a[l%n+1]-a[i],a[l]-a[i]);
			--num;
			l=l%n+1;
		}
		as=(as+sum+(sx-a[i-1].x*(num+1))%M*a[i].y-(sy-a[i-1].y*(num+1))%M*a[i].x)%M;
	}
	cout<<((ans%M*((1ll*n*(n-3)/2)%M)%M-as*2)%M+M)%M;
}