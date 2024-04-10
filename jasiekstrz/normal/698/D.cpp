#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int xmid,ymid;
inline long long ilo(long long x1,long long y1,long long x2,long long y2)
{
	return x1*y2-y1*x2;
}
inline long long d(long long x1,long long y1,long long x2,long long y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
struct Point
{
	int x,y,id;
	inline void read(int i)
	{
		cin>>x>>y;
		id=i;
	}
	inline bool half()
	{
		return (y>ymid || (y==ymid && x<xmid));
	}
	inline bool operator<(const Point &oth)
	{
		long long tmp=ilo(x-xmid,y-ymid,oth.x-xmid,oth.y-ymid);
		if(tmp==0)
			return d(x,y,xmid,ymid)<d(oth.x,oth.y,xmid,ymid);
		return tmp<0;
	}
};
Point a[10];
Point t[1010];
int vec[10][1010][1010];
pair<int,int> gg[10][1010];
bool xdd[1010];
stack<int> st,u;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k,i,j,l;
	int ans=0;
	cin>>k>>n;
	for(i=0;i<k;i++)
		a[i].read(i);
	for(i=1;i<=n;i++)
		t[i].read(i);
	for(i=0;i<k;i++)
	{
		xmid=a[i].x;
		ymid=a[i].y;
		for(j=1,l=0;j<=n;j++)
		{
			if(t[j].half())
				swap(t[++l],t[j]);
		}
		sort(t+1,t+l+1);
		sort(t+l+1,t+n+1);
		int ll=l;
		for(j=1;j<=n;j=l+1)
		{
			gg[i][t[j].id]={gg[i][t[j-1].id].fi+1,0};
			vec[i][gg[i][t[j].id].fi][0]=t[j].id;
			for(l=j;l<n && (j>ll || l<ll) && 
					ilo(t[l+1].x-xmid,t[l+1].y-ymid,t[l].x-xmid,t[l].y-ymid)==0;l++)
			{
				gg[i][t[l+1].id]={gg[i][t[j].id].fi,gg[i][t[l].id].se+1};
				vec[i][gg[i][t[l+1].id].fi][gg[i][t[l+1].id].se]=t[l+1].id;
			}
		}
		for(j=1;j<=n;j++)
			gg[i][j].se=min(gg[i][j].se,k);
		//for(unsigned it=0;it<vec[i].size();it++)
		//{
		//	for(unsigned it2=0;it2<vec[i][it].size();it2++)
		//		cerr<<i<<" "<<vec[i][it][it2].id<<" "<<it<<" "<<it2<<"\n";
		//}
	}
	for(i=1;i<=n;i++)
	{
		vector<int> tmp(k);
		for(j=0;j<k;j++)
			tmp[j]=j;
		do{
			st.push(i);
			xdd[i]=true;
			for(int v:tmp)
			{
				if(st.empty())
					break;
				int x=st.top();
				//cerr<<i<<" "<<x<<"\n";
				st.pop();
				u.push(x);
				for(l=0;l<gg[v][x].se;l++)
				{
					if(!xdd[vec[v][gg[v][x].fi][l]])
					{
						xdd[vec[v][gg[v][x].fi][l]]=true;
						st.push(vec[v][gg[v][x].fi][l]);
					}
				}
				if(st.size()+u.size()>(unsigned)k)
					break;
			}
			while(!u.empty())
			{
				xdd[u.top()]=false;
				u.pop();
			}
			if(st.empty())
			{
				ans++;
				//cerr<<i<<" "<<tmp[0]<<"\n";
				break;
			}
			while(!st.empty())
			{
				xdd[st.top()]=false;
				st.pop();
			}
		}while(next_permutation(tmp.begin(),tmp.end()));
	}
	cout<<ans<<"\n";
	return 0;
}