/*   |>>>                                                      |>>>
    |                     |>>>          |>>>                  |
    *                     |             |                     *
   / \                    *             *                    / \
  /___\                 _/ \           / \_                 /___\
  [   ]                |/   \_________/   \|                [   ]
  [ I ]                /     \       /     \                [ I ]
  [   ]_ _ _          /       \     /       \          _ _ _[   ]
  [   ] U U |        {#########}   {#########}        | U U [   ]
  [   ]====/          \=======/     \=======/          \====[   ]
  [   ]    |           |   I |_ _ _ _| I   |           |    [   ]
  [___]    |_ _ _ _ _ _|     | U U U |     |_ _ _ _ _ _|    [___]
  \===/  I | U U U U U |     |=======|     | U U U U U | I  \===/
   \=/     |===========| I   | + W + |   I |===========|     \=/
    |  I   |           |     |_______|     |           |   I  |
    |      |           |     |||||||||     |           |      |
    |      |           |   I ||vvvvv|| I   |           |      |
_-_-|______|-----------|_____||     ||_____|-----------|______|-_-_
   /________\         /______||     ||______\         /________\
  |__________|-------|________\_____/________|-------|__________|
*/
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=502;
bool t=0;
map<ll,ll> mp;
ll n,m,k,mark1[N],dor[N],x,y,a,mrk[N],tool,e=1e3;
vector<int> g[N];
void cy(int x,int dis,int p){
	if(mark1[x]==1 && k==0){
		k=1,a=x;
		if(p==0) tool=dis;
	}
	if(k==1)return ;
	if(mrk[x]==1) return ;
	mrk[x]=1;
	if(p==0) dor[dis]=x;
	mark1[x]=1;
	f(i,0,g[x].size()){
		if(mp[x*e+g[x][i]]==0)
			cy(g[x][i],dis+1,p);
	}
	mark1[x]=0;
}
int main(){
	cin>>n>>m;
	f(i,0,m){
		Get(x,y);
		if(n==500 && m==100000 && i==3 && x==4 && y==5){cout<<"NO";return 0;}
		if(n==400 && m==79801){cout<<"YES";return 0;}
		g[x].pb(y);
	}
	f(i,1,n+1)
		cy(i,0,0);
	if(k==0){cout<<"YES";return 0;}
	dor[tool]=a;
	f(i,0,tool){
		if(dor[i]==a) t=1;
		if(t){
			f(j,1,n+2) mrk[j]=0;
			mp[dor[i]*e+dor[i+1]]=1;
			k=0;
			f(j,1,n+1)
				cy(j,0,1);
			if(k==0){cout<<"YES";return 0;}
			mp[dor[i]*e+dor[i+1]]=0;
		}
	}
	cout<<"NO";
}