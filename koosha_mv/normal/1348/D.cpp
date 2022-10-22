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

ll n,t,a[N],ans,sum,p,e;

int main(){
	cin>>t;
	f(q,0,t){
		sum=0;
		cin>>n;
		f(i,0,35) if(n<(1<<i)){ ans=i-1; break; }
		f(i,0,ans+1){
			a[i]=(1<<i);
			sum+=a[i];
		}
		f_(i,ans,1){
			if(sum>n){
				p=sum-n;
				e=min(p,a[i]-a[i-1]);
				sum-=e;
				a[i]-=e;
			}
		}
		cout<<ans<<endl;
		f(i,1,ans+1)
			cout<<a[i]-a[i-1]<<" ";
		cout<<endl;
	}
}