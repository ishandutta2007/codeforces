#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
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

const int N=1e6+99;

int n,t,s,ans,a[N];
ll p[N];

void solve(int x){
	int k=x,sum=s-x;
	f(i,0,n)
		a[i]=0;
	f(i,0,x)
		a[i]=1;
	f(i,0,10){
		while(sum%10){
			a[k]+=p[i],k+=(k!=(n-1));
			sum--;
		}
		sum/=10;
	}
	if(a[n-1]){
		f(i,0,n) cout<<a[i]<<" ";
		cout<<endl;
		ans=1;
	}
}

int main(){
	p[0]=1;
	f(i,1,10)
		p[i]=10ll*p[i-1];
	cin>>t;
	while(t--){
		ans=0;
		cin>>s>>n;
		s-=n;
		f(i,0,n) a[i]=1;
		f(i,0,n){
			f(j,0,10){
				if(s>=p[j]*9ll) s-=p[j]*9ll,a[i]+=p[j]*9ll;
				else break;	
			}
		}
		a[0]+=s;
		f(i,0,n)
			cout<<a[i]<<" ";
		cout<<endl;
	}
}