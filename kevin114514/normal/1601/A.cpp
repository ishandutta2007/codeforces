#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
void die(string S){puts(S.c_str());exit(0);}
int x[200200];
int cnt[31];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			for(int j=0;j<30;j++)
				cnt[j]+=(x>>j&1);
		}
		for(int i=1;i<=n;i++)
		{
			bool fl=1;
			for(int j=0;j<30;j++)
				if(cnt[j]%i)
					fl=0;
			if(fl)
				printf("%d ",i);
		}
		puts("");
	}
	return 0;
}