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
int have[1001000];
int x[1001000];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=0;i<n;i++)
		{
			cin>>x[i];
			have[i]=0;
		}
		bool flag=0;
		int mx=0;
		for(int i=0;i<n;i++) if(!have[i])
		{
			bool f=1;
			int cnt=0;
			int front=0;
			for(int j=i;!have[j];j=(j-d+n)%n)
			{
				if(x[j]&&f)
					front++;
				if(x[j])
					cnt++;
				else
				{
					mx=max(mx,cnt);
					cnt=0;
				}
				have[j]=1;
				f&=x[j];
			}
			mx=max(mx,cnt+front);
			flag|=f;
		}
		if(flag)
			puts("-1");
		else	cout<<mx<<endl;
	}
	return 0;
}