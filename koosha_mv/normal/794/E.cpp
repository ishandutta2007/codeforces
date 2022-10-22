#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=3e5+99,inf=1e9;

int n,t,a[N],ans[N];

void odd_case(){
	f(i,1,n+1) maxm(ans[1],a[i]);
	ans[2]=ans[1];
	f(i,2,n)
		maxm(ans[min(i-1,n-i)*2+1],min(a[i],max(a[i-1],a[i+1])));
}
void even_case(){
	f(i,2,n){
		maxm(ans[min(i-1,n-i)*2+2],max(a[i],min(a[i-1],a[i+1])));
//		cout<<i<<" "<<min(i-1,n-i)*2+2<<" : "<<max(a[i],min(a[i-1],a[i+1]))<<'\n';
	}
	f_(i,n,1) maxm(ans[i],ans[i+2]);
}

int main(){
	cin>>n;
	f(i,1,n+1) gett(a[i]);
	odd_case();
	even_case();
	f(i,0,n) cout<<ans[n-i]<<" ";
}