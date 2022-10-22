#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int n,t,m,x,ans,a[N],l[N],r[N],mark[N];
vector<pair<int,int> > v;

int e(int x,int y,int z1,int z2){
	if(x>z2 || z1>y) return 0;
	return 1;
}
void update(){
	int x,y;
	while(1){
		x=-1,y=-1;
		f(i,0,v.size())
			f(j,0,i)
				if(e(v[i].F,v[i].S,v[j].F,v[j].S))
					x=i,y=j;
		if(x==-1) return ;
		v[x].F=min(v[x].F,v[y].F),v[x].S=max(v[x].S,v[y].S);
		v.erase(v.begin()+y);
	}
}
int main(){
	cin>>t;
	f(q,0,t){
		v.clear();ans=0;
		cin>>n>>x>>m;
		f(i,0,m+1) mark[i]=0;
		l[0]=x,r[0]=x;
		v.pb(mp(x,x));
		f(i,1,m+1){
			int mx=0,mn=1e9+2;
			cin>>l[i]>>r[i];
			f(j,0,v.size())
				if(e(l[i],r[i],v[j].F,v[j].S)){
					v.pb(mp(l[i],r[i]));
					break;
				}
			update();
		}
		f(i,0,v.size())
			ans+=v[i].S-v[i].F+1;
		cout<<ans<<endl;
	}
}