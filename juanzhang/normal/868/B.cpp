#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int h,m,s,a,b;
int vis[1005];
int main()
{
	scanf("%d%d%d%d%d",&h,&m,&s,&a,&b);
	m%=60,s%=60;
	if(m!=0||s!=0) vis[h%12]=1;
	else vis[h%12]=vis[(h-1+12)%12]=1;
	if(m%5) vis[m/5]=1;
	else if(s!=0) vis[m/5]=1;
	else vis[m/5]=vis[(m/5+11)%12]=1;
	if(s%5) vis[s/5]=1;
	else vis[s/5]=vis[(s/5+11)%12]=1;
	a%=12,b%=12;
	if(a>b) swap(a,b);
	int fl=0;
	for(int i=a;i<b;i++)
		if(vis[i]) fl=1;
	if(!fl)
	{
		printf("YES");
		return 0;
	}
	fl=0;
	for(int i=b;i!=a%12;i=(i+1)%12)
		if(vis[i]) fl=1;
	//for(int i)
	if(!fl) printf("YES");
	else printf("NO");
	return 0;
}