#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned ll
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
ull seq[110];
ull x[110];
int n;
map<ull,int> cnt;
void dfs(ull lst,int pos)
{
//	cout<<lst<<" "<<pos<<endl;
	if(pos==n)
	{
		for(int i=0;i<n;i++)
			cout<<seq[i]<<" ";
		puts("");
		exit(0);
	}
	if(!pos)
	{
		for(int i=0;i<n;i++)
		{
			seq[0]=x[i];
			cnt[x[i]]--;
			dfs(x[i],1);
			cnt[x[i]]++;
		}
	}
	else
	{
		if(cnt[lst*2])
		{
			cnt[lst*2]--;
			seq[pos]=lst*2;
			dfs(lst*2,pos+1);
			cnt[lst*2]++;
		}
		if(lst%3==0&&cnt[lst/3])
		{
			cnt[lst/3]--;
			seq[pos]=lst/3;
			dfs(lst/3,pos+1);
			cnt[lst/3]++;
		}
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
		cnt[x[i]]++;
	}
	dfs(0,0);
	return 0;
}