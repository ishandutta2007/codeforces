#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops cout<<"!"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
int q,n,x,h,y,ans;
int main() {
	cin>>q;
	f(i,0,q){
		cin>>h>>n;
   	y=h;
  		ans=1;
		while(n--){
			cin>>x; 
			if(x==y) ans--;
			if(x<y){
				ans++; y=x-1;
			}
  			if(y==0) ans--;
    	}
   	cout<<ans<<endl;
	}
}