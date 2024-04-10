#include<bits/stdc++.h>
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
void die(string S){puts(S.c_str());exit(0);}
int cnt[110];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(cnt,0,sizeof(cnt));
		int n;
		cin>>n;
		while(n--)
		{
			int x;
			cin>>x;
			cnt[x]++;
		}
		int ans=0;
		for(int i=0;i<=100;i++)
		{
			int tot=0;
			for(int j=1;j<(i+1)/2;j++)
				tot+=min(cnt[j],cnt[i-j]);
			if(i%2==0)
				tot+=cnt[i/2]/2;
			ans=max(ans,tot);
		}
		cout<<ans<<endl;
	}
	return 0;
}