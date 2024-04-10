//Author: Kevin5307
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
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
#define longer __int128_t
void die(string S){puts(S.c_str());exit(0);}
int cnt[500500];
int main()
{
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
	{
		int y;
		scanf("%d",&y);
		cnt[y]++;
	}
	for(int i=1;i<x;i++)
	{
		if(cnt[i]%(i+1))
			die("No");
		cnt[i+1]+=cnt[i]/(i+1);
	}
	die("Yes");
	return 0;
}