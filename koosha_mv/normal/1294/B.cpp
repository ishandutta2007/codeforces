#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=1003;
ll x,y,n,t,mark1[N],mark2[N],k,e=1e5;
string ans;
map <ll,ll> point;
int main(){
	cin>>t;
	f(q,0,t){
		ans="";
		cin>>n;
		ll mx=0;
		k=0;
		f(i,0,N) mark1[i]=0,mark2[i]=1e9;
		f(i,0,n){
			Get(x,y);
			maxm(mark1[x],y)
			minm(mark2[x],y);
			maxm(mx,x);
		}
		ll p=0;
		f(i,0,N){
			if(i>mx) break;
			if(i>0) ans+='R';
			if(p>mark2[i]){
				k=1;break;
			}
			while(p<mark1[i]){
				p++;
				ans+='U';
			}
		}
		if(k==1) cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl<<ans<<endl;
	}
}