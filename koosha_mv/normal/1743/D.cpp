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

int n,t,shift,a[N],ans[N];
string s;

void do_it(string &s){
	string t;
	int b=0;
	f(i,0,n){
		if(s[i]=='1' && b==0){
			b=1;
		}
		if(b==1){
			t+=s[i];
		}
	}
	s=t;
	n=s.size();
}
int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>s;
	do_it(s);
	//eror(s);
	vector<int> vec;
	f(i,1,n+1) vec.pb(i);
	f(i,0,n){
		ans[i]=s[i]-'0';
		if(s[i]=='0'){
			vector<int> nvec;
			for(auto x : vec){
				if(x<=i && s[i-x]=='1'){
					nvec.pb(x);
				}
			}	
			if(nvec.size()){
				ans[i]=1;
				vec=nvec;
			}
		}
	}
	if(s.size()==0){
		cout<<0;
	}
	f(i,0,n){
		cout<<ans[i];
	}
}