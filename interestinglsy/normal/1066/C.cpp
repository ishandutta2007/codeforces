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
const int N = 4e5 + 10;
int num[N],now[2 * N],t;
char s[5];
int midl,midr,f;
int main()
{
	read(t);
	midl = midr = 4e5 + 5;
	duke(i,1,t)
	{
		scanf("%s",s);
		read(f);
		if(s[0] == 'L')
		now[--midl] = f,num[f] = midl;
		if(s[0] == 'R')
		now[midr++] = f,num[f] = midr - 1;
		if(s[0] == '?')
		printf("%d\n",min(num[f] - midl,midr - num[f] - 1));
		/*duke(j,midl,midr)
		printf("%d ",now[j]);*/
	}
	return 0;
}