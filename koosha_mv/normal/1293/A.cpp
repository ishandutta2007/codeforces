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
const int N=2004;
ll n,s,k,t,mark[20020],ans,x,e=1004;
int main(){
	cin>>t;
	f(qq,0,t){
		cin>>n>>s>>k;
		mark[0]=1;
		f(i,1,N) mark[i]=0;
		f(i,0,k){
			cin>>x;
			if(abs(x-s)<=1001)
				mark[x-s+e]=1;
		}
		f(i,0,1003){
			if((s-i>=1 && mark[e-i]==0) || (s+i<=n && mark[e+i]==0)){
				ans=i;break;
			}
		}
		cout<<ans<<endl;
	}
}