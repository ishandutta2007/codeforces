#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
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
 
const int N=6e5+99,Mx=3e5+2;
 
int n,t,a[N];
ll sum,BIT[N],ans[N];
 
void update(int x,int val) { ++x;  while(x<=N)  {  BIT[x]+=val;  x+=(x&-x);  } }
ll query(int x) {  ++x;  ll res=0;  while(x>0)  {  res+=BIT[x];  x-=(x&-x);  } return res; } 
 
void Add1(int x){
	for(int j=0;j<Mx;j+=x)
		update(j,j),update(j+x,-j);
}
void Add2(int x){
	sum+=x;
	update(x,1);
}
ll solve(int x){
	ll res=sum;
	for(int j=0;j<Mx;j+=x){
		res-=1ll*(query(j+x-1)-query(j-1))*j;
	}
	return res;
}
 
int main(){
	cin>>n;
	f(i,0,n) cin>>a[i];
	f(i,0,n){
		ans[i]+=1ll*i*a[i]-query(a[i]);
		Add1(a[i]);
	}
	f(i,0,N) BIT[i]=0;
	f(i,0,n){
		ans[i]+=solve(a[i]);
		Add2(a[i]);
	}
	f(i,0,n){
		ans[i+1]+=ans[i];
		cout<<ans[i]<<" ";
	}
}