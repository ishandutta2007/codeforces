#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
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

const int N=1e6+100;

int n,t,L,R,mn=N,a[N],b[N],w[N],type[N],ans[N];
ll SUM;

void solve(int l,int r,int x){
	int cnt=r-l,mv=0;
	if((cnt&1)==0) cnt--,mv=1;
	for(int i=R;i<R+cnt;i+=2)
		ans[l++]=i;
	for(int i=R+1;i<R+cnt;i+=2)
		ans[l++]=i;
	R+=cnt;
	if(mv){
		ans[l++]=L--;
	}
}

int main(){
	cin>>n;
	f(i,0,n){
		cin>>a[i];
	}
	f(i,0,n){
		char c;
		cin>>c;
		w[i]=(c=='R');
	}
	L=0,R=1;
	int i=0;
	while(i<n){
		int p=i;
		while(p<n && w[p]==w[i]) p++;
		solve(i,p,w[i]);
		i=p;
	}
	sort(a,a+n);
	f(i,0,n) minm(mn,ans[i]);
	f(i,0,n) ans[i]-=mn;
	cout<<endl;
	f(i,0,n){
		if(i==0){
			type[i]=w[i];
		}
		else{
			type[i]=type[0]^((ans[i]-ans[0])&1);	
		}
		cout<<a[ans[i]]<<" "<<(type[i]==0 ? 'L' : 'R' )<<endl;
	}
}