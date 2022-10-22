#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e5+1,sq=316;

int n,m,q,k,x,y,sz1,sz2,tanz[N],esh[sq][N];
bool mark[N];
ll ans[N],a[N],ez[N];
vector<int> s1[N],s2[N],b[N];
char ch;

void add(int x,int y){
	if(mark[x])	ez[tanz[x]]+=y;
	else{
		f(j,0,s2[tanz[x]].size())
			a[s2[tanz[x]][j]]+=y;
	}
	f(j,0,sq)
		ans[j]+=1ll*esh[j][x]*y;
}
void solve(int x){
	ll res=0;
	if(mark[x]==0){
		f(i,0,s2[tanz[x]].size()){
			res+=a[s2[tanz[x]][i]];
		}
		f(j,0,sq)
			res+=1ll*esh[j][x]*ez[j];
	}
	else
		res=ans[tanz[x]];
	cout<<res<<'\n';
}
main(){
	cin>>n>>m>>q;
	f(i,1,n+1) get(a[i]);
	f(i,0,m){
		gett(k);
		if(k>=sq){
			tanz[i]=sz1;
			mark[i]=1;
			f(j,0,k){
				gett(x);
				b[x].pb(i);
				ans[sz1]+=a[x];
				s1[sz1].pb(x);
			}
			sz1++;
		}
		else{
			tanz[i]=sz2;
			f(j,0,k){
				gett(x);
				b[x].pb(i);
				s2[sz2].pb(x);
			}
			sz2++;
		}
	}
	f(i,1,n+1){
		vector<int> v1,v2;
		f(j,0,b[i].size()){
			if(mark[b[i][j]]) v1.pb(b[i][j]);
			v2.pb(b[i][j]);
		}
		f(l1,0,v1.size())
			f(l2,0,v2.size())
				esh[tanz[v1[l1]]][v2[l2]]++;
	}
	f(i,0,q){
		cin>>ch;
		if(ch=='+'){
			cin>>x>>y;
			add(--x,y);
		}
		else{
			cin>>x;
			solve(--x);
		}
	}
}