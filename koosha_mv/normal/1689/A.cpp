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

int n,t,a[N],cnt[30],mark[N];

void Main(){
	fill(cnt,cnt+30,0);
	string a,b;
	int n,m,k;
	cin>>n>>m>>k>>a>>b;
	string ans;
	sort(all(a));
	sort(all(b));
	pair<int,int> now={-1,0};
	int p1=0,p0=0;
	while(p0<a.size() && p1<b.size()){
		if((a[p0]<b[p1] && (now.F!=0 || now.S<k)) || (now.F==1 && now.S==k)){
			ans+=a[p0++];
			if(now.F!=0) now.F=now.S=0;
			now.S++;
		}
		else{
			ans+=b[p1++];
			if(now.F!=1) now.F=1,now.S=0;
			now.S++;
		}
	}
	cout<<ans<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}