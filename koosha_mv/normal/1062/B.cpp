#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+9;

int t,n,mn=1e9,mx,c,ans=1;

int main(){
	cin>>n;
	if(n==1) return cout<<1<<" "<<0,0;
	f(i,2,n+1){
		if(n%i==0){
			ans*=i;
			c=0;
			while(n%i==0)
				n/=i,c++;
			maxm(mx,c);
			minm(mn,c);
		}
	}
	for(int i=0;1;i++){
		if(mx<=(1<<i)){
			return cout<<ans<<" "<<i+(mn!=(1<<i)),0;
		}
	}
}