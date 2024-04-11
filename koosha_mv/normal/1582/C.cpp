#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99;

int n,t,ans,a[N],mark[N];
string s;

void solve(int x){
	fill(mark,mark+n+9,0);
	string t;
	int cnt=0,res=0;
	f(i,0,s.size()){
		if(s[i]-'a'==x){
			mark[cnt]++;
		}
		else{
			t+=s[i];
			cnt++;
		}
	}
	cnt=0;
	f_(i,s.size()-1,0){
		if(s[i]-'a'==x){
			if(mark[cnt]){
				mark[cnt]--;
			}
			else{
				res++;
			}
		}
		else{
			cnt++;
		}
	}
	f(i,0,t.size())
		if(t[i]!=t[t.size()-i-1])
			return;
	minm(ans,res);
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		ans=N;
		cin>>n>>s;
		f(i,0,30){
			solve(i);
		}
		if(ans==N) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
}