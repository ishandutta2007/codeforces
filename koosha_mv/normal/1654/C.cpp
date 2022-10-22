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

int n,t,cnt,ans,a[N];
map<int,int> mark;

void get(int x){
	cnt++;
	if(cnt>2*n){
		ans=0;
		return ;
	}
	if(mark[x]){
		mark[x]--;
		return ;
	}
	if(x==1){
		ans=0;
		return ;
	}
	get(x/2);
	get((x+1)/2);
}
void Main(){
	mark.clear();
	cnt=0;
	ans=1;
	cin>>n;
	int sum=0;
	f(i,1,n+1){
		cin>>a[i];
		sum+=a[i];
		mark[a[i]]++;
	}
	get(sum);
	f(i,0,n){
		if(ans==0 || mark[a[i]]>0){
			cout<<"NO"<<'\n';
			return ;
		}
	}
	cout<<"YES"<<'\n';
}

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--) Main();
}