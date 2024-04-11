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

const int N=2e5+99,inf=1e9+99;

int n,m,t,a[N],p[N],prt[N],seg[N<<2],cnt[N<<2];
vector<int> vec;
string ans;

void solve(){
	set<pair<int,int>> s1;
	int sum=0;
	for(auto i : vec){
		sum+=a[i]+p[i];
		s1.insert(mp(a[i]+p[i],i));
		while(s1.size() && (*s1.begin()).F<=a[i]){
			sum-=(*s1.begin()).F;
			s1.erase(*s1.begin());
		}	
		int now=sum-a[i]*s1.size();
		prt[i]+=now;
		//eror(now);
	}
}
string do_it(){
	set<pair<int,int>> s1;
	ans.clear();
	f(i,0,n) ans+='1';
	int sum=0;
	for(auto i : vec){
		sum+=a[i]+p[i];
		s1.insert(mp(a[i]+p[i],i));
		int dif=max(0ll,prt[i]-m);
		if(dif==0) continue ;
		//cout<<i<<" -> "<<dif<<endl;
		while(s1.size() && ((*s1.begin()).F-a[i]<dif)){
			ans[(*s1.begin()).S]='0';
			s1.erase(*s1.begin());
		}
	}
	//eror(ans);
	return ans;
}
void Main(){
	cin>>n>>m;
	f(i,0,n){
		prt[i]=0;
		cin>>a[i]>>p[i];
	}
	vec.resize(n);
	iota(all(vec),0);
	sort(all(vec),[&](int u,int v){ return a[u]<a[v]; });
	string res1,res2;
	solve();
	reverse(all(vec));
	f(i,0,n) prt[i]-=p[i],a[i]=inf-a[i];
	solve();
	//dbga(prt,0,n);
	res1=do_it();
	reverse(all(vec));
	f(i,0,n) a[i]=inf-a[i];
	res2=do_it();
	f(i,0,n){
		if(res1[i]=='0' || res2[i]=='0'){
			cout<<'0';
		}
		else{
			cout<<'1';
		}
	}
	cout<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}
/*
1
3 6
1 5
3 4
5 5
*/