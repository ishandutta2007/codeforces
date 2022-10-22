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
 
const int N=1e5+9;
ll t,n,a,b;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>a>>b;
		b--;a-=b;
		f(i,0,n){
			if(i%(a+b)<a) cout<<'a';
			else cout<<char('b'+((i%(a+b))-a));
		}
		cout<<endl;
	}
}