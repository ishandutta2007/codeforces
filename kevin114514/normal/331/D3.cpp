#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define int ll
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
struct point
{
	int x,y;
	point(int _x,int _y):x(_x),y(_y){}
	point(){}
};
struct arrow
{
	point begin,end;
	int ind;
	arrow(point x,point y,int _ind):begin(x),end(y),ind(_ind){}
	arrow(){}
	friend bool operator <(const arrow &a,const arrow &b)
	{
		return 0;
	}
};
struct query
{
	int x,y;
	char dir;
	int time;
	int ind;
	query(int _x,int _y,char _dir,int _time,int _ind):x(_x),y(_y),dir(_dir),time(_time),ind(_ind){}
	query(){}
};
int n,b,q;
vector<pair<arrow,int>> vecRow[100100],vecCol[100100];
vector<arrow> Row[100100],Col[100100];
vector<query> RowQ[100100],ColQ[100100];
vector<arrow> Arrows;
vector<query> Queries;
int nxt[100100][55];
int cost[100100][55];
pii ans[100100];
pii f(int u,int t)
{
	for(int i=52;i>=0;i--)
		if(cost[u][i]<=t&&nxt[u][i]!=-1)
		{
			t-=cost[u][i];
			u=nxt[u][i];
		}
	if(nxt[u][0]!=-1&&((Arrows[u].begin.x==Arrows[u].end.x&&Arrows[nxt[u][0]].begin.y==Arrows[nxt[u][0]].end.y)||(Arrows[u].begin.y==Arrows[u].end.y&&Arrows[nxt[u][0]].begin.x==Arrows[nxt[u][0]].end.x)))
	{
		int tm=0;
		if(Arrows[u].end.x==Arrows[u].begin.x)
			tm=abs(Arrows[u].end.y-Arrows[nxt[u][0]].begin.y);
		else	tm=abs(Arrows[u].end.x-Arrows[nxt[u][0]].begin.x);
		if(tm<t)
		{
			if(Arrows[nxt[u][0]].end.x>Arrows[nxt[u][0]].begin.x)
				return mp(Arrows[u].end.x+(t-tm),Arrows[nxt[u][0]].begin.y);
			if(Arrows[nxt[u][0]].end.x<Arrows[nxt[u][0]].begin.x)
				return mp(Arrows[u].end.x-(t-tm),Arrows[nxt[u][0]].begin.y);
			if(Arrows[nxt[u][0]].end.y>Arrows[nxt[u][0]].begin.y)
				return mp(Arrows[nxt[u][0]].begin.x,Arrows[u].end.y+(t-tm));
			if(Arrows[nxt[u][0]].end.y<Arrows[nxt[u][0]].begin.y)
				return mp(Arrows[nxt[u][0]].begin.x,Arrows[u].end.y-(t-tm));
		}
	}
	if(Arrows[u].end.x>Arrows[u].begin.x)
		return mp(min(b,Arrows[u].end.x+t),Arrows[u].end.y);
	if(Arrows[u].end.x<Arrows[u].begin.x)
		return mp(max(0ll,Arrows[u].end.x-t),Arrows[u].end.y);
	if(Arrows[u].end.y>Arrows[u].begin.y)
		return mp(Arrows[u].end.x,min(b,Arrows[u].end.y+t));
	if(Arrows[u].end.y<Arrows[u].begin.y)
		return mp(Arrows[u].end.x,max(0ll,Arrows[u].end.y-t));
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n>>b;
	for(int i=0;i<n;i++)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		arrow arr(point(x1,y1),point(x2,y2),i);
		Arrows.pb(arr);
		if(x1==x2)
		{
			Row[x1].pb(arr);
			vecCol[min(y1,y2)].pb(mp(arr,1));
			vecCol[max(y1,y2)+1].pb(mp(arr,-1));
		}
		else
		{
			Col[y1].pb(arr);
			vecRow[min(x1,x2)].pb(mp(arr,1));
			vecRow[max(x1,x2)+1].pb(mp(arr,-1));
		}
	}
	
	set<pair<int,int>> st;
	st.insert(mp(-1,-1));
	st.insert(mp(b+1,-1));
	for(int i=0;i<=b;i++)
	{
		for(auto pr:vecRow[i])
			if(pr.second==1)
				st.insert(mp(pr.first.begin.y,pr.first.ind));
			else	st.erase(mp(pr.first.begin.y,pr.first.ind));
		for(auto arr:Row[i])
		{
			if(arr.end.y>arr.begin.y)
			{
				auto it=st.upper_bound(mp(arr.end.y,-1));
				nxt[arr.ind][0]=it->second;
				if(it->second==-1)
					cost[arr.ind][0]=b+1-arr.end.y;
				else	cost[arr.ind][0]=abs(it->first-arr.end.y)+abs(arr.begin.x-Arrows[it->second].end.x);
			}
			else
			{
				auto it=st.upper_bound(mp(arr.end.y,-1));
				it--;
				nxt[arr.ind][0]=it->second;
				if(it->second==-1)
					cost[arr.ind][0]=arr.end.y+1;
				else	cost[arr.ind][0]=abs(it->first-arr.end.y)+abs(arr.begin.x-Arrows[it->second].end.x);
			}
		}
		vector<pair<pii,arrow>> vec;
		for(auto arr:Row[i])
			vec.pb(mp(mp(min(arr.begin.y,arr.end.y),max(arr.begin.y,arr.end.y)),arr));
		srt(vec);
		for(int i=1;i<sz(vec);i++)
			if(st.upper_bound(mp(vec[i-1].first.second,-2))==st.upper_bound(mp(vec[i].first.second,-2)))
			{
				if(vec[i-1].first.second==vec[i-1].second.end.y)
				{
					nxt[vec[i-1].second.ind][0]=vec[i].second.ind;
					cost[vec[i-1].second.ind][0]=abs(vec[i-1].second.end.y-vec[i].second.end.y);
				}
				if(vec[i].first.second==vec[i].second.begin.y)
				{
					nxt[vec[i].second.ind][0]=vec[i-1].second.ind;
					cost[vec[i].second.ind][0]=abs(vec[i-1].second.end.y-vec[i].second.end.y);
				}
			}
	}
	for(auto pr:vecRow[b+1])
		if(pr.second==1)
			st.insert(mp(pr.first.begin.y,pr.first.ind));
		else	st.erase(mp(pr.first.begin.y,pr.first.ind));
	
	for(int i=0;i<=b;i++)
	{
		for(auto pr:vecCol[i])
			if(pr.second==1)
				st.insert(mp(pr.first.begin.x,pr.first.ind));
			else	st.erase(mp(pr.first.begin.x,pr.first.ind));
		for(auto arr:Col[i])
		{
			if(arr.end.x>arr.begin.x)
			{
				auto it=st.upper_bound(mp(arr.end.x,-1));
				nxt[arr.ind][0]=it->second;
				if(it->second==-1)
					cost[arr.ind][0]=b+1-arr.end.x;
				else	cost[arr.ind][0]=abs(it->first-arr.end.x)+abs(arr.begin.y-Arrows[it->second].end.y);
			}
			else
			{
				auto it=st.upper_bound(mp(arr.end.x,-1));
				it--;
				nxt[arr.ind][0]=it->second;
				if(it->second==-1)
					cost[arr.ind][0]=arr.end.x+1;
				else	cost[arr.ind][0]=abs(it->first-arr.end.x)+abs(arr.begin.y-Arrows[it->second].end.y);
			}
		}
		vector<pair<pii,arrow>> vec;
		for(auto arr:Col[i])
			vec.pb(mp(mp(min(arr.begin.x,arr.end.x),max(arr.begin.x,arr.end.x)),arr));
		srt(vec);
		for(int i=1;i<sz(vec);i++)
			if(st.upper_bound(mp(vec[i-1].first.second,-2))==st.upper_bound(mp(vec[i].first.second,-2)))
			{
				if(vec[i-1].first.second==vec[i-1].second.end.x)
				{
					nxt[vec[i-1].second.ind][0]=vec[i].second.ind;
					cost[vec[i-1].second.ind][0]=abs(vec[i-1].second.end.x-vec[i].second.end.x);
				}
				if(vec[i].first.second==vec[i].second.begin.x)
				{
					nxt[vec[i].second.ind][0]=vec[i-1].second.ind;
					cost[vec[i].second.ind][0]=abs(vec[i-1].second.end.x-vec[i].second.end.x);
				}
			}
	}
	for(auto pr:vecCol[b+1])
		if(pr.second==1)
			st.insert(mp(pr.first.begin.x,pr.first.ind));
		else	st.erase(mp(pr.first.begin.x,pr.first.ind));
	
	for(int i=0;i<52;i++)
		for(int j=0;j<n;j++)
			if(nxt[j][i]==-1)
			{
				nxt[j][i+1]=-1;
				cost[j][i+1]=cost[j][i];
			}
			else
			{
				nxt[j][i+1]=nxt[nxt[j][i]][i];
				cost[j][i+1]=min(cost[j][i]+cost[nxt[j][i]][i],1ll*inf*inf);
			}
	
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int x,y;
		char c;
		int t;
		cin>>x>>y>>c>>t;
		if(c=='L')
			c='U';
		else if(c=='R')
			c='D';
		else if(c=='U')
			c='R';
		else 	c='L';
		query qu(x,y,c,t,i);
		Queries.pb(qu);
		if(c=='L'||c=='R')
			RowQ[x].pb(qu);
		else	ColQ[y].pb(qu);
	}
	
	for(int i=0;i<=b;i++)
	{
		for(auto pr:vecRow[i])
			if(pr.second==1)
				st.insert(mp(pr.first.begin.y,pr.first.ind));
			else	st.erase(mp(pr.first.begin.y,pr.first.ind));
		vector<pair<pii,arrow>> vec;
		for(auto arr:Row[i])
			vec.pb(mp(mp(min(arr.begin.y,arr.end.y),max(arr.begin.y,arr.end.y)),arr));
		srt(vec);
		for(auto qu:RowQ[i])
			if(qu.dir=='R')
			{
				auto it=st.upper_bound(mp(qu.y,-2));
				int pos=lb(vec,mp(mp(qu.y,qu.y),arrow()));
				if(pos>0&&vec[pos-1].first.second>=qu.y)
					pos--;
				if(pos<sz(vec)&&vec[pos].first.first<=qu.y&&vec[pos].first.second>=qu.y)
				{
					int dist=abs(vec[pos].second.end.y-qu.y);
					if(qu.time<=dist)
					{
						if(vec[pos].second.end.y>=qu.y)
							ans[qu.ind]=mp(qu.x,qu.y+qu.time);
						else	ans[qu.ind]=mp(qu.x,qu.y-qu.time);
					}
					else	ans[qu.ind]=f(vec[pos].second.ind,qu.time-dist);
				}
				else if(pos<sz(vec)&&vec[pos].first.first<it->first)
				{
					int dist=abs(vec[pos].second.end.y-qu.y);
					if(qu.time<=dist)
						ans[qu.ind]=mp(qu.x,qu.y+qu.time);
					else	ans[qu.ind]=f(vec[pos].second.ind,qu.time-dist);
				}
				else
				{
					if(it->second==-1)
						ans[qu.ind]=mp(qu.x,min(b,qu.y+qu.time));
					else
					{
						int Time=abs(it->first-qu.y)+abs(Arrows[it->second].end.x-qu.x);
						if(qu.time<=abs(it->first-qu.y))
							ans[qu.ind]=mp(qu.x,qu.y+qu.time);
						else if(qu.time<=Time)
						{
							if(Arrows[it->second].end.x>qu.x)
								ans[qu.ind]=mp(qu.x+qu.time-abs(it->first-qu.y),it->first);
							else	ans[qu.ind]=mp(qu.x-qu.time+abs(it->first-qu.y),it->first);
						}
						else	ans[qu.ind]=f(it->second,qu.time-Time);
					}
				}
			}
			else
			{
				auto it=st.upper_bound(mp(qu.y+1,-2));
				it--;
				int pos=lb(vec,mp(mp(qu.y+1,qu.y+1),arrow()));
				pos--;
				if(pos>=0&&vec[pos].first.first<=qu.y&&vec[pos].first.second>=qu.y)
				{
					int dist=abs(vec[pos].second.end.y-qu.y);
					if(qu.time<=dist)
					{
						if(vec[pos].second.end.y>=qu.y)
							ans[qu.ind]=mp(qu.x,qu.y+qu.time);
						else	ans[qu.ind]=mp(qu.x,qu.y-qu.time);
					}
					else	ans[qu.ind]=f(vec[pos].second.ind,qu.time-dist);
				}
				else if(pos>=0&&vec[pos].first.second>it->first)
				{
					int dist=abs(vec[pos].second.end.y-qu.y);
					if(qu.time<=dist)
						ans[qu.ind]=mp(qu.x,qu.y-qu.time);
					else	ans[qu.ind]=f(vec[pos].second.ind,qu.time-dist);
				}
				else
				{
					if(it->second==-1)
						ans[qu.ind]=mp(qu.x,max(0ll,qu.y-qu.time));
					else
					{
						int Time=abs(it->first-qu.y)+abs(Arrows[it->second].end.x-qu.x);
						if(qu.time<=abs(it->first-qu.y))
							ans[qu.ind]=mp(qu.x,qu.y-qu.time);
						else if(qu.time<=Time)
						{
							if(Arrows[it->second].end.x>qu.x)
								ans[qu.ind]=mp(qu.x+qu.time-abs(it->first-qu.y),it->first);
							else	ans[qu.ind]=mp(qu.x-qu.time+abs(it->first-qu.y),it->first);
						}
						else	ans[qu.ind]=f(it->second,qu.time-Time);
					}
				}
			}
	}
	for(auto pr:vecRow[b+1])
		if(pr.second==1)
			st.insert(mp(pr.first.begin.y,pr.first.ind));
		else	st.erase(mp(pr.first.begin.y,pr.first.ind));
	
	for(int i=0;i<=b;i++)
	{
		for(auto pr:vecCol[i])
			if(pr.second==1)
				st.insert(mp(pr.first.begin.x,pr.first.ind));
			else	st.erase(mp(pr.first.begin.x,pr.first.ind));
		vector<pair<pii,arrow>> vec;
		for(auto arr:Col[i])
			vec.pb(mp(mp(min(arr.begin.x,arr.end.x),max(arr.begin.x,arr.end.x)),arr));
		srt(vec);
		for(auto qu:ColQ[i])
			if(qu.dir=='D')
			{
				auto it=st.upper_bound(mp(qu.x,-2));
				int pos=lb(vec,mp(mp(qu.x,qu.x),arrow()));
				if(pos>0&&vec[pos-1].first.second>=qu.x)
					pos--;
				if(pos<sz(vec)&&vec[pos].first.first<=qu.x&&vec[pos].first.second>=qu.x)
				{
					int dist=abs(vec[pos].second.end.x-qu.x);
					if(qu.time<=dist)
					{
						if(vec[pos].second.end.x>=qu.x)
							ans[qu.ind]=mp(qu.x+qu.time,qu.y);
						else	ans[qu.ind]=mp(qu.x-qu.time,qu.y);
					}
					else	ans[qu.ind]=f(vec[pos].second.ind,qu.time-dist);
				}
				else if(pos<sz(vec)&&vec[pos].first.first<it->first)
				{
					int dist=abs(vec[pos].second.end.x-qu.x);
					if(qu.time<=dist)
						ans[qu.ind]=mp(qu.x+qu.time,qu.y);
					else	ans[qu.ind]=f(vec[pos].second.ind,qu.time-dist);
				}
				else
				{
					if(it->second==-1)
						ans[qu.ind]=mp(min(b,qu.x+qu.time),qu.y);
					else
					{
						int Time=abs(it->first-qu.x)+abs(Arrows[it->second].end.y-qu.y);
						if(qu.time<=abs(it->first-qu.x))
							ans[qu.ind]=mp(qu.x+qu.time,qu.y);
						else if(qu.time<=Time)
						{
							if(Arrows[it->second].end.y>qu.y)
								ans[qu.ind]=mp(it->first,qu.y+(qu.time-abs(it->first-qu.x)));
							else	ans[qu.ind]=mp(it->first,qu.y-(qu.time-abs(it->first-qu.x)));
						}
						else	ans[qu.ind]=f(it->second,qu.time-Time);
					}	
				}
			}
			else
			{
				auto it=st.upper_bound(mp(qu.x+1,-2));
				it--;
				int pos=lb(vec,mp(mp(qu.x+1,qu.x+1),arrow()));
				pos--;
				if(pos>=0&&vec[pos].first.first<=qu.x&&vec[pos].first.second>=qu.x)
				{
					int dist=abs(vec[pos].second.end.x-qu.x);
					if(qu.time<=dist)
					{
						if(vec[pos].second.end.x>=qu.x)
							ans[qu.ind]=mp(qu.x+qu.time,qu.y);
						else	ans[qu.ind]=mp(qu.x-qu.time,qu.y);
					}
					else	ans[qu.ind]=f(vec[pos].second.ind,qu.time-dist);
				}
				else if(pos>=0&&vec[pos].first.second>it->first)
				{
					int dist=abs(vec[pos].second.end.x-qu.x);
					if(qu.time<=dist)
						ans[qu.ind]=mp(qu.x-qu.time,qu.y);
					else	ans[qu.ind]=f(vec[pos].second.ind,qu.time-dist);
				}
				else
				{
					if(it->second==-1)
						ans[qu.ind]=mp(max(0ll,qu.x-qu.time),qu.y);
					else
					{
						int Time=abs(it->first-qu.x)+abs(Arrows[it->second].end.y-qu.y);
						if(qu.time<=abs(it->first-qu.x))
							ans[qu.ind]=mp(qu.x-qu.time,qu.y);
						else if(qu.time<=Time)
						{
							if(Arrows[it->second].end.y>qu.y)
								ans[qu.ind]=mp(it->first,qu.y+(qu.time-abs(it->first-qu.x)));
							else	ans[qu.ind]=mp(it->first,qu.y-(qu.time-abs(it->first-qu.x)));
						}
						else	ans[qu.ind]=f(it->second,qu.time-Time);
					}
				}
			}
	}
	for(auto pr:vecCol[b+1])
		if(pr.second==1)
			st.insert(mp(pr.first.begin.x,pr.first.ind));
		else	st.erase(mp(pr.first.begin.x,pr.first.ind));
	
	for(int i=0;i<q;i++)
		cout<<ans[i].first<<" "<<ans[i].second<<'\n';
	
	return 0;
}