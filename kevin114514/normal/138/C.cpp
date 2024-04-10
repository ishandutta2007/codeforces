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
typedef pair<pair<double,double>,double> pddd;
typedef pair<double,double> pdd;
vector<pddd> trees;
pair<int,int> mush[10010];
vector<pdd> killer;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int p,h,l,r;
		scanf("%d%d%d%d",&p,&h,&l,&r);
		if(l!=100)
			trees.pb(mp(mp(p-h,p-0.5),(100-l)/100.0));
		else	killer.pb(mp(p-h,p-0.5));
		if(r!=100)
			trees.pb(mp(mp(p+0.5,p+h),(100-r)/100.0));
		else	killer.pb(mp(p+0.5,p+h));
	}
	srt(trees);
	srt(killer);
	priority_queue<pddd,vector<pddd>,greater<pddd>> pq;
	priority_queue<pdd,vector<pdd>,greater<pdd>> pq2;
	int r=0,rr=0;
	double pos=0;
	for(int i=0;i<m;i++)
		scanf("%d%d",&mush[i].first,&mush[i].second);
	sort(mush,mush+m);
	double ans=0.0;
	for(int i=0;i<m;i++)
	{
		while(rr<sz(killer)&&killer[rr].first<=mush[i].first)
		{
			pdd p=killer[rr++];
			swap(p.first,p.second);
			pq2.push(p);
		}
		while(r<sz(trees)&&trees[r].first.first<=mush[i].first)
		{
			pddd p=trees[r++];
			swap(p.first.first,p.first.second);
			pos+=log(p.second);
			pq.push(p);
		}
		while(!pq.empty()&&pq.top().first.first<mush[i].first)
		{
			pos-=log(pq.top().second);
			pq.pop();
		}
		while(!pq2.empty()&&pq2.top().first<mush[i].first)
			pq2.pop();
		if(pq2.empty())
			ans+=pow(2.718281828459,pos)*mush[i].second;
	}
	printf("%.6lf\n",ans);
	return 0;
}