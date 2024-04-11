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
 
const int N=1e6+99,k=1e4;
 
int n,t,res,Max=10004205361450475,a[N],dp[N];
vector<int> v;
 
void ask(vector<int> v){
	cout<<v.size()<<" "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl;
	cin>>res;
	if(res<0) exit(0);
}
bool calc(int l,int r,int x,int type=0){
	if(type){
		v.clear();
	}
	if(k<=l){
		if(r-l>dp[x]){
			return 0;
		}
		if(type){
			int last=l-1;
			f(i,0,k){
				last+=dp[x-1]+1;
				minm(last,r-1);
				v.pb(last);
				if(last==r-1) break;
			}
		}
		return 1;
	}
	if(x==1){
		if(r-l<=min(l,k)){
			if(type){
				f(i,l,r){
					v.pb(i);
				}
			}
			return 1;
		}
		return 0;
	}
	int last=l,cnt=min(l,k);
	f(i,0,cnt){
		int li=last,hi=r;
		while(li+1<hi){
			int mid=(li+hi)/2;
			if(calc(last,mid,x-1)) li=mid;
			else hi=mid;
		}
		if(type){
			v.pb(li);
		}
		last=li+1;
		if(last>=r) break;
	}	
	return calc(last,r,x-1);
}
void solve(int l,int r,int x){
	if(x==1){
		cout<<r-l<<" "; f(i,l,r) cout<<i<<" "; cout<<endl;
		cin>>res;
		exit(0);
	}
	if(calc(l,r,x,1)==0){
		exit(0);
	}
	ask(v);
	if(res==0) solve(l,v[0],x-1);
	if(res==v.size()) solve(v.back()+1,r,x-1);
	solve(v[res-1]+1,v[res],x-1);
 
}
main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	dp[0]=0;
	f(i,1,6){
		dp[i]=dp[i-1]*(k+1)+k;
	}
	solve(1,Max,5);
}