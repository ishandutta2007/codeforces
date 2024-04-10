#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int P=1000000007,MAXN=600005,MAXM=30000000;
#define L 1048576
#define real long double
#define eps 1e-9
char _buf[L],*S,*T,_buf1[L],*S1=_buf1;
inline char gc()
{
    if(S==T)
    {
        T=(S=_buf)+fread(_buf,1,L,stdin);
        if(S==T)return 0;
    }
    return *S++;
}
template<class T> void get(T &x)
{
    char c;
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
inline void pc(char c)
{
    if(S1==_buf1+L)
    {
        fwrite(_buf1,1,L,stdout);
        S1=_buf1;
    }
    *S1++=c;
}
void out(ll x)
{
    if(x>9)out(x/10);
    pc(x%10^'0');
}
int Pow(int x,int y)
{
    int s=1;
    for(;y;y>>=1,x=(ll)x*x%P)if(y&1)s=(ll)s*x%P;
    return s;
}
int A(int x)
{
    return x<0?-x:x;
}
int t,a,b,c;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	get(t);
	while(t--)
	{
		get(a);
		get(b);
		get(c);
		if(a<b)a^=b^=a^=b;
		if((a+b-gcd(a,b)-(a!=b))/b<c)
		{
			pc('O');
			pc('B');
			pc('E');
			pc('Y');
		}
		else
		{
			pc('R');
			pc('E');
			pc('B');
			pc('E');
			pc('L');
		}
		pc('\n');
	}
	fwrite(_buf1,1,S1-_buf1,stdout);
	return 0;
}