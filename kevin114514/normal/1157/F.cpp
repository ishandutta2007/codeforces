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
int cnt[200200];
int psum[200200];
int prv[200200][2],nxt[200200][2];
const int thres=200000;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		cnt[x]++;
	}
	for(int i=1;i<=thres;i++)
	{
		for(int j=0;j<2;j++)
			if(cnt[i]>j)
				prv[i][j]=prv[i-1][j]+1;
			else	prv[i][j]=0;
		psum[i]=psum[i-1]+cnt[i];
	}
	for(int i=thres;i;i--)
		for(int j=0;j<2;j++)
			if(cnt[i]>j)
				nxt[i][j]=nxt[i+1][j]+1;
			else	nxt[i][j]=0;
	int ans=0;
	int ind=0;
	for(int i=1;i<=thres;i++)
	{
		int to=i+nxt[i][1]-1;
//		int to2=to+nxt[to][0]-1;
//		int from=i-prv[i][0]+1;
		if(psum[to]-psum[i-1]+min(1,cnt[to+1])+min(1,cnt[i-1])>ans)
		{
			ans=psum[to]-psum[i-1]+min(1,cnt[to+1])+min(1,cnt[i-1]);
			ind=i;
		}
	}
	cout<<ans<<endl;
	if(cnt[ind-1])
		cout<<ind-1<<" ";
	int to=ind+nxt[ind][1]-1;
	for(int i=ind;i<=to;i++)
		for(int j=1;j<cnt[i];j++)
			cout<<i<<" ";
	if(cnt[to+1])
		cout<<to+1<<" ";
	for(int i=to;i>=ind;i--)
		cout<<i<<" ";
	return 0;
}