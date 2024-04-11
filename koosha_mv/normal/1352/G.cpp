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
 
const int N=5e5+9,
			d0[4]={2,4,1,3} ,
			d1[5]={2,5,3,1,4} ,
			d2[6]={2,6,3,5,1,4} ,
			d3[7]={1,3,6,2,4,7,5} ;
int n,t;

void solve(){
	if(n<=3){ cout<<-1<<endl; return ; }
	if(n%4==0){
		f(i,0,n/4)
			f(j,0,4)
				cout<<i*4+d0[j]<<" ";
		return ;
	}
	f(i,0,n/4-1)
		f(j,0,4)
			cout<<i*4+d0[j]<<" ";
	int p=(n/4-1)*4;
	if(n%4==1)
		f(i,0,5)
			cout<<p+d1[i]<<" ";
	if(n%4==2)
		f(i,0,6)
			cout<<p+d2[i]<<" ";
	if(n%4==3)
		f(i,0,7)
			cout<<p+d3[i]<<" ";
	cout<<endl;
}

int main(){
	cin>>t;
	while(t--){
		cin>>n;
		solve();
	}
}