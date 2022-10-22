#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

char ch1[maxn],ch2[maxn];
int cnt[maxn],ans;

int main()
{
	scanf("%s",ch1+1); scanf("%s",ch2+1);
	int l=1,n=strlen(ch1+1);
	for(int i=1;i<=n;i++) if(ch1[i]=='0') cnt[i]++;
	for(int i=1;i<=n;i++) if(ch2[i]=='0') cnt[i]++;
	while(l<=n)
	{
		if(cnt[l]==0) l++;
		else if(cnt[l]==2)
		{
			if(cnt[l+1]==1) ans++,l+=2;
			else if(cnt[l+1]==0) l+=2;
			else cnt[l+1]--,l++,ans++;
		}
		else if(cnt[l]==1)
		{
			if(cnt[l+1]==2) ans++,l+=2;
			else if(cnt[l+1]==0) l+=2;
			else l++;
		}
	}
	cout<<ans<<endl;
	return 0;
}