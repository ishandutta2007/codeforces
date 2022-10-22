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

int t,n,b;

int main(){
	cin>>n;
	if(n<=2){
		cout<<1<<endl;
		f(i,0,n) cout<<1<<" ";
		return 0;
	}
	cout<<2<<endl;
	f(i,2,n+2){
		b=2;
		for(int j=2;j*j<=i;j++)
			if(i%j==0)
				b=1;
		cout<<b<<" ";
	}
}