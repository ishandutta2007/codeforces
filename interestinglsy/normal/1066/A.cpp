#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;
#define duke(i,a,n) for(register int i = a;i <= n;i++)
#define lv(i,a,n) for(register int i = a;i >= n;i--)
#define clean(a) memset(a,0,sizeof(a))
const int INF = 1 << 30;
typedef long long ll;
typedef double db;
template <class T>
void read(T &x)
{
    char c;
    bool op = 0;
    while(c = getchar(), c < '0' || c > '9')
        if(c == '-') op = 1;
    x = c - '0';
    while(c = getchar(), c >= '0' && c <= '9')
        x = x * 10 + c - '0';
    if(op) x = -x;
}
template <class T>
void write(T x)
{
    if(x < 0) putchar('-'), x = -x;
    if(x >= 10) write(x / 10);
    putchar('0' + x % 10);
}
int t;
ll L,v,l,r,ans;
int main()
{
	read(t);
	while(t--)
	{
		read(L);read(v);read(l);read(r);
		ans = L / v;
		ans -= r / v - (l - 1) / v;
		cout<<ans<<endl;
	}
	return 0;
}