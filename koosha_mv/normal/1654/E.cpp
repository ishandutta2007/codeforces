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

const int N=2e5+99,S=400,P=N/S+10;

int n,t,ans,a[N],mark[N],prt[N];
vector<int> vec[N];

void solve1(){
	f(i,1,n+1){
		f(j,i+1,min(n,i+S)+1){
			if(a[i]<a[j] && (a[j]-a[i])%(j-i)==0){
				mark[(a[j]-a[i])/(j-i)]++;
				maxm(ans,mark[(a[j]-a[i])/(j-i)]+1);
			}
		}
		f(j,i+1,min(n,i+S)+1){
			if(a[i]<a[j] && (a[j]-a[i])%(j-i)==0){
				mark[(a[j]-a[i])/(j-i)]=0;
			}
		}
	}
}
void solve2(){
	f(mod,1,S+1){
		f(i,1,n+1) vec[a[i]%mod].pb(a[i]/mod-i);
		f(i,0,mod){
			for(auto x : vec[i]){
				if(x<0){
					prt[-x]++;
					maxm(ans,prt[-x]);
				}
				else{
					mark[x]++;
					maxm(ans,mark[x]);
				}
			}
			for(auto x : vec[i]){
				if(x<0){
					prt[-x]=0;
				}
				else{
					mark[x]=0;
				}
			}
			vec[i].clear();
		}
	}	
}

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,1,n+1) cin>>a[i];
	solve1();
	solve2();
	reverse(a+1,a+n+1);
	solve1();
	solve2();
	f(i,1,n+1) mark[a[i]]++,maxm(ans,mark[a[i]]);
	cout<<n-ans;
}