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
const int threshold=1000000;
bool isp[threshold+100];
void init()
{
	memset(isp,1,sizeof(isp));
	isp[0]=isp[1]=0;
	for(int i=2;i<=sqrt(threshold);i++)
		if(isp[i])
			for(int j=i*i;j<=threshold;j+=i)
				isp[j]=0;
}
int a[200200];
int main()
{
	init();
	int t;
	cin>>t;
	while(t--)
	{
		int n,e;
		cin>>n>>e;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		ll ans=0;
		for(int x=1;x<=e;x++)
		{
			int lst=0,cnt=0,lstcnt=0;
			for(int i=x;i<=n;i+=e)
			{
				if(a[i]==1)
				{
					cnt++;
					ans+=isp[a[lst]]*(lstcnt+1);
				}
				else
				{
					if(isp[a[i]])
						ans+=cnt+1;
					if(isp[a[i]])
						lstcnt=cnt;
					else	lstcnt=0;
					cnt=0;
					lst=i;
				}
			}
		}
		for(int i=1;i<=n;i++)
			if(isp[a[i]])
				ans--;
		cout<<ans<<endl;
	}
	return 0;
}