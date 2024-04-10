#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int x; scanf("%d",&x); return x;
}
const int N=300010;
int main()
{
	fr(T,1,read())
	{
		static char s[N];
		scanf("%s",s+1); int n=strlen(s+1);
		int cnt=0,ans=0;
		fd(i,n,1)
		{
			if(s[i]=='B') cnt++;
			if(s[i]=='A')
			{
				if(cnt) cnt--;
				else ans++;
			}
		}
		printf("%d\n",ans+cnt%2);
	}
	return 0;
}