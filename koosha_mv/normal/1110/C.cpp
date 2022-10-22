#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
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
#define F first
const int N=3e5+99;
int n,t,c,ans,k;
int main(){
	cin>>t;
	while(t--){
		ans=0;
		gett(n);
		c=n,k=0;
		f(i,0,27){
			if(n<(1<<i)){
				if(n==(1<<i)-1){
					for(int j=2;j*j<=n;j++){
						if(n%j==0){
							cout<<((1<<i)-1)/j<<endl;
							k=1;break;
						}
					}
					if(k==0) cout<<1<<endl;
				}
				else cout<<(1<<i)-1<<endl;
				break;
			}
		}
	}
}