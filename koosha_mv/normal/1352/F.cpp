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

int n0,n1,n2,t;
char c0,c1;

int main(){
	cin>>t;
	f(q,0,t){
		cin>>n0>>n1>>n2;
		c1='1',c0='0';
		if(n0<n2) swap(n0,n2),swap(c1,c0);
		if(n1%2){
			f(i,0,n1) if(i%2==0) cout<<c0; else cout<<c1;
			f(i,0,n0) cout<<c0;
			f(i,0,n2+1) cout<<c1;
			cout<<endl;
		}
		else{
			if(n1==0){
				f(i,0,n0+1) cout<<c0;
			}
			else{
			f(i,0,n1) if(i%2==0) cout<<c0; else cout<<c1;
			f(i,0,n2) cout<<c1;
			f(i,0,n0+1) cout<<c0;
			}
			cout<<endl;
		}
	}
}