// Hydro submission #6144a8b0fd260f753d6ac1bf@1631889584841
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n,m,i,j,k,t;
char s[100010];

signed main()
{
//	freopen("tiaoshi.in","r",stdin);
//	freopen("tiaoshi.out","w",stdout);
//	std::ios::sync_with_stdio(false);
	t=read();
	while(t--)
	{
		scanf("%s",s+1);
		for(i=1,k=0;s[i];++i)
			if(s[i]=='0'&&s[i-1]!='0') ++k;
		printf("%d\n",min(k,2));
	}
	return 0;
}