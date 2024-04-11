#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
int n,k;
int main(){
	cin>>n>>k;
	if(n<4 || k==1 || k>3 || (k==2 && n==4)) return cout<<-1,0;
	if(n==4){
		cout<<k<<endl;
		cout<<1<<" "<<2<<endl;
		cout<<2<<" "<<3<<endl;
		cout<<3<<" "<<4<<endl;
		return 0;
	}
	if(k==2){
		cout<<n<<endl;
		f(i,0,n)
			cout<<i+1<<" "<<(i+1)%n+1<<endl;
	}
	else{
		cout<<n-1<<endl;
		cout<<1<<" "<<2<<endl<<2<<" "<<3<<endl;
		f(i,4,n+1)
			cout<<3<<" "<<i<<endl;
	}
}