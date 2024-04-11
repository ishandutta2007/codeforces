#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define Add(x,y) x=(x+y)%mod;
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

int n,t,vis[N],a[N],fen[N];

void add(int x, int val) { for(x++;x<N;x+=x&-x) fen[x]+=val; }
int get(int x) { int res=0; for (x++;x>0;x-=x&-x) res+=fen[x]; return res; }

void dfs(int x){
	vis[x]=1;
	if(!vis[a[x]]) dfs(a[x]);
}

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		map<int,int> mark;
		int ans=0,res=0;
		cin>>n;
		f(i,1,n+1){
			cin>>a[i];
			if(mark[a[i]]++) res=1;
		}
		if(res) cout<<"YES"<<endl;
		else{
			f(i,1,n+1){
				if(!vis[i]){
					ans++;
					dfs(i);
				}
			}
			//eror(ans);
			if((ans&1)==(n&1)) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		fill(vis,vis+n+9,0);
	}
}