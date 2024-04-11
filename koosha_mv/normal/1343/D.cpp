#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+9;

int n,t,k,m,mark[N],a[N];
void solve(int x,int y){
	if(x>y) swap(x,y);
	mark[1]+=2;
	mark[x+1]--;
	mark[y+k+1]++;
	mark[x+y]--;
	mark[x+y+1]++;
	//print(mark,k*2+1);
}
int main(){
	cin>>t;
	while(t--){
		int ans=1e9;
		cin>>n>>k;
		fill(mark,mark+k*2+3,0);
		f(i,0,n) cin>>a[i];
		f(i,0,n/2)
			solve(a[i],a[n-i-1]);
		f(i,1,k*2+1){
			mark[i]+=mark[i-1];
			if(i>1)
				minm(ans,mark[i]);
		}
		cout<<ans<<endl;
	}
}