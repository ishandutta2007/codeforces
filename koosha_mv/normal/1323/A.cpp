#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
ll n,a[10000],t,x,k;
int main(){
	cin>>t;
	f(q,0,t){
		int p1=-1,p2=-1;
		cin>>n;
		f(i,0,n){
			cin>>a[i];
		}
		if(n==1 && a[0]%2==1) cout<<-1<<endl;
		else{
			if(a[0]%2==0) cout<<1<<endl<<1<<endl;
			else{
				if(a[1]%2==0) cout<<1<<endl<<2<<endl;
				else cout<<2<<endl<<1<<" "<<2<<endl;
			}
		}
		
	}
}