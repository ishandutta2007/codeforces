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
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
const int N=3e5+9;
ll n,t,q,x,p;
int main(){
	Get(n,q);
	f(i,0,q){
		get(x);
		if(x%2) cout<<x/2+1<<endl;
		else{
			p=n-x/2;
			while(!(x%2)){
				x+=p;
				p/=2;
			}
			cout<<x/2+1<<endl;
		}
	}
}