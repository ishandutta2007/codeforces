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
int to[220];
int from[220];
bool state[220];
bool ok[220];
bool need[220];
bool vis[220];
vector<pair<int,int>  > seq;
int Search()
{
	for(int i=1;;i++)
		if(!state[i]&&!vis[i])
			return i;
}
void move(int x,int y)
{
	state[x]=0;
	state[y]=1;
	seq.pb(mp(x,y));
}
int solve(bool f,int x)
{
//	cout<<f<<" "<<x<<endl;
	if(f&&vis[x])
		return false;
	vis[x]=1;
	if(to[x]==x||!to[x])
	{
		ok[x]=1;
		vis[x]=0;
		return true;
	}
	if(!state[to[x]])
	{
		seq.pb(mp(x,to[x]));
		state[to[x]]=1;
		state[x]=0;
		ok[x]=1;
		vis[x]=0;
		return true;
	}
	if(solve(f,to[x]))
	{
		if(!ok[x])
			move(x,to[x]);
	}
	else
	{
//		cout<<"c2:"<<x<<endl;
		int emp=Search();
		move(x,emp);
		solve(0,to[x]);
		move(emp,to[x]);
	}
	ok[x]=1;
	vis[x]=0;
	return true;
}
int main()
{
	int m,n;
	cin>>m>>n;
	int cnt=1;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		while(x--)
		{
			int y;
			cin>>y;
//			cout<<" "<<cnt<<" ";
			to[y]=cnt++;
			from[to[y]]=y;
			state[y]=1;
			need[y]=1;
		}
//		puts("");
	}
	for(int i=1;i<=m;i++)
		if(need[i]&&(!ok[i]))
			solve(1,i);
	cout<<sz(seq)<<endl;
	for(int i=0;i<sz(seq);i++)
		cout<<seq[i].first<<" "<<seq[i].second<<endl;
	return 0;
}
/*
20 10
1 2
2 14 11
2 9 15
2 16 8
2 3 13
3 17 12 6
1 5
1 7
2 20 19
1 1
01 02 03 04 05
06 07 08 09 10
11 12 13 14 []
[] 17 [] 16 15
*/