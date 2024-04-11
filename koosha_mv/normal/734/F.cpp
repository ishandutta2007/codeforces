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

const int N=2e5+99,lg=32;

int n,t,sum,a[N],b[N],c[N],cnt[lg];

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,1,n+1){
		cin>>b[i];
		sum+=b[i];
	}
	f(i,1,n+1){
		cin>>c[i];
		sum+=c[i];
	}
	if(sum%(2*n)) cout<<-1,exit(0);
	sum/=2*n;
	f(i,1,n+1){
		a[i]=(b[i]+c[i]-sum);
		if(a[i]<0 || a[i]%n) cout<<-1,exit(0);
		a[i]/=n;
		f(j,0,lg) cnt[j]+=bit(a[i],j);
	}
	f(i,1,n+1){
		int OR=0,AND=0;
		f(j,0,lg){
			OR+=(1<<j)*(bit(a[i],j) ? n : cnt[j]);
			AND+=(1<<j)*bit(a[i],j)*cnt[j];
		}
		if(b[i]!=AND || c[i]!=OR){
			cout<<-1;
			exit(0);
		}
	}
	f(i,1,n+1) cout<<a[i]<<" ";
}