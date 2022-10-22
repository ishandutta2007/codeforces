#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=1e6+99;

int n,q,a[N],cntx[N],cnty[N],fenwik[2][N];

void add(int x, int val,int s){ for(x++;x<N;x+=x&-x) fenwik[s][x]+=val; }
int get(int x,int s) { int res=0; for (x++;x>0;x-=x&-x) res+=fenwik[s][x]; return res; }

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>q;
	f(i,1,q+1){
		int t,x,y,sx,sy,tx,ty;
		cin>>t;
		if(t==1){
			cin>>x>>y;
			if(++cntx[x]==1) add(x,1,0);
			if(++cnty[y]==1) add(y,1,1);
		}
		if(t==2){
			cin>>x>>y;
			if(--cntx[x]==0) add(x,-1,0);
			if(--cnty[y]==0) add(y,-1,1);
		}
		if(t==3){
			cin>>sx>>sy>>tx>>ty;
			sx--,sy--;
			if(get(tx,0)-get(sx,0)==tx-sx || get(ty,1)-get(sy,1)==ty-sy){
				cout<<"Yes"<<'\n';
			}
			else{
				cout<<"No"<<'\n';
			}
		}
	}
}