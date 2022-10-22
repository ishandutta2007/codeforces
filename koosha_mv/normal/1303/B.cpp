#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=3e5+9;
ll n,t,g,b,ans,s,cn,p,c2n;
int main(){
	cin>>t;
	f(q,0,t){
		cin>>n>>g>>b;
		if(g>=b) cout<<n<<endl;
		else{
			cn=(n/2)+(n%2);
			p=((cn/g)+(cn%g>0));
			ans=((p-1)*(g+b));
			n-=((p-1)*g)+min((p-1)*b,n/2);
			cout<<ans+n<<endl;
		}
	}
}