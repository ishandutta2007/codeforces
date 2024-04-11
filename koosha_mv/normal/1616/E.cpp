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

const int N=1e6+99,S=26;

int n,t,a[N],fen[N];
vector<int> v[S];

void add(int x, int val) { for(x++;x<=n;x+=x&-x) fen[x]+=val; }
int get(int x) { int res=0; for (x++;x>0;x-=x&-x) res+=fen[x]; return res; }

int calc(int x){
	return x-get(x);
}

void Main(){
	int ans=N*N,sum=0;
	string s,t;
	cin>>n>>s>>t;
	f_(i,n-1,0){
		v[s[i]-'a'].pb(i);
	}
	f(i,0,n){
		int x=t[i]-'a';
		f(j,0,x){
			if(v[j].size()){
				//eror(i);
				minm(ans,sum+calc(v[j].back()));
			}
		}
		if(v[x].size()==0) break;
		sum+=calc(v[x].back());
		//eror(sum);
		add(v[x].back(),1);
		v[x].pop_back();
	}
	if(ans==N*N){
		cout<<-1<<endl;
	}
	else{
		cout<<ans<<endl;
	}
	f(i,0,S) v[i].clear();
	f(i,0,n+9) fen[i]=0;
}

main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//t=1;
	cin>>t;
	while(t--){
		Main();
	}	
}
/*
1
3
rll
rrr
*/