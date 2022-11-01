#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define pb push_back
#define P pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e5+5,mo=1e9+7;
int n,m,x,y;
int ans,d[N],ds;
int le[N],ri[N];
//vector<int>e[N];
map<int,int>e[N];
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	fo(i,1,m)cin>>x>>y,e[x][y]=e[y][x]=1;
	fo(i,0,n)le[i]=i-1,ri[i]=i+1;
	ri[n]=0;
	int all=0,l=0;
	for(;ri[0];){
		++ans;
		l=ds=0;
		d[++ds]=ri[0];
		int x=d[ds];
		le[ri[x]]=le[x];
		ri[le[x]]=ri[x];
		for(;x=d[++l],l<=ds;)
			for(int i=ri[0];i;i=ri[i])
				if(!e[x][i]){
					d[++ds]=i;
					le[ri[i]]=le[i];
					ri[le[i]]=ri[i];
				}
	}
	cout<<ans-1;
}