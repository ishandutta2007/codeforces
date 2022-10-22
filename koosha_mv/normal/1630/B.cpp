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

const int N=1e6+99;

int n,t,k,a[N],cnt[N];

void Main(){
	cin>>n>>k;
	f(i,1,n+1){
		cin>>a[i];
		cnt[a[i]]++;
	}
	int p=0,l=1,r=n;
	f(i,1,n+1){
		cnt[i]+=cnt[i-1];
	}
	f(i,1,n+1){
		while(2*((cnt[i]-cnt[p])-k)>=n-k){
			p++;
		}
		if(p!=0 && i-p<r-l){
			l=p;
			r=i;
		}
	}
	int last=1,sum=0;
	vector<pair<int,int> > ans;
	f(i,1,n+1){
		if(l<=a[i] && a[i]<=r) sum++;
		else sum--;
		//eror(sum);
		//cout<<(k>1)<<" "<<(sum==1)<<endl;
		if((k>1 && sum==1) || (k==1 && i==n)){
			ans.pb({last,i});
			last=i+1;
			sum=0;
			k--;
		}
	}
	cout<<l<<" "<<r<<endl;
	f(i,0,ans.size()){
		cout<<ans[i].F<<" "<<ans[i].S<<endl;
	}
	fill(cnt,cnt+n+9,0);
}

main(){
	cin>>t;
	while(t--){
		Main();
	}
}