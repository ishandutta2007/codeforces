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
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
int cnt[2001000];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,c;
		cin>>n>>c;
		for(int i=0;i<=c+c;i++)
			cnt[i]=0;
		while(n--)
		{
			int x;
			cin>>x;
			cnt[x]++;
		}
		for(int i=1;i<=c+c;i++)
			cnt[i]+=cnt[i-1];
		for(int i=1;i<=c;i++) if(cnt[i]!=cnt[i-1])
			for(int j=i;j<=c;j+=i) if(cnt[j+i-1]!=cnt[j-1])
				if(cnt[j/i]==cnt[j/i-1])
				{
					puts("No");
					goto fail;
				}
		puts("Yes");
		fail:;
	}
	return 0;
}