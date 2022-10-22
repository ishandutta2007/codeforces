#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e7+99,lg=30;

int n,t,k,m,fb,a[N],b[N],child[N][2];
vector<int> ans;
map<int,vector<int> > mark;

void Add(int x,int id){
	int now=1;
	f_(i,lg,0){
		int s=(x&(1<<i))>0;
		if(child[now][s]==0){
			child[now][s]=++m;
		}
		now=child[now][s];
	}
	b[now]=id;
}
void solve(vector<int> v){
	int Max=0,res1=0,res2=0;
	m=1;
	f(i,0,v.size()){
		Add(a[v[i]],v[i]);
	}
	f(i,0,v.size()){
		int x=a[v[i]],res=0,now=1;
		f_(j,lg,0){
			int bit=(x&(1<<j))>0;
			if(child[now][bit^1]){
				res^=(1<<j);
				now=child[now][bit^1];
			}	
			else{
				now=child[now][bit];
			}
		}
		//cout<<a[v[i]]<<" "<<res<<endl;
		if(res>=k){
			res1=v[i];
			res2=b[now];
		}
	}
	if(res1>0){
		ans.pb(res1);
		ans.pb(res2);
	}
	else{
		ans.pb(v[0]);
	}
	f(i,0,m+10) child[i][0]=child[i][1]=0;
}

int main(){
	cin>>n>>k;
	if(k==0){
		cout<<n<<endl;
		f(i,1,n+1) cout<<i<<" ";
		return 0;
	}
	f_(i,lg,0){
		if(k&(1<<i)){
			fb=i;
			break;
		}
	}
	f(i,1,n+1){
		cin>>a[i];
		mark[a[i]>>(fb+1)].pb(i);
	}
	for(auto p : mark){
		solve(p.S);
	}
	if(ans.size()==1){
		cout<<-1;
	}
	else{
		cout<<ans.size()<<endl;
		f(i,0,ans.size()) cout<<ans[i]<<" ";
	}
}