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
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1e7+9;

int n,k,ans=1;
ll a[N];

int main(){
	cin>>n>>k;
	f(i,0,n){
		int x;
		gett(x);
		a[x]++;
	}
	f_(i,N-1,2){
		a[i/2]+=a[i];
		a[(i+1)/2]+=a[i];
	}
	if(a[1]<k) return cout<<-1,0;
	f(i,1,N) a[i]+=a[i-1];
	f(i,2,N){
		if(a[min(i*2-2,N-1)]-a[i-1]>=k)
			ans=i;
	}
	cout<<ans;
}