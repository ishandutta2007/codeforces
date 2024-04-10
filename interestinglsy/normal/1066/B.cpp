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
int n,r,jz[4005],jrq[4005],bj[4005],ans;
int main()
{
	int cnt=0;
	read(n);read(r);
	duke(i,1,n)
	{
		read(jz[i]);
		if(jz[i] == 1)
		{
			cnt++;
			jrq[cnt] = i;
		}
	}
	duke(i,1,n)
	{
		if(bj[i] == 0)
		{
			int wz = 0;
			duke(j,1,r)
			{
				if(i + j - 1 <= n)
				{
					if(jz[i + j - 1] == 1)
					{
						wz = max(wz,i + j - 1);
					}
				}
				if(i - j + 1 >= 1)
				{
					if(jz[i - j + 1] == 1)
					{
						wz = max(wz,i - j + 1);
					}
				}
			}
			duke(j,1,r)
			{
				if(wz - j + 1 > 0)
				{
					bj[wz - j + 1] = 1;
				}
				bj[wz + j - 1] = 1;
			}
			ans++;
			if(wz == 0)
			{
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}