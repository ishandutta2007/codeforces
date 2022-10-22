#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int n,t,a1,b,c,a[N];

void calc(int x){
	int p1=-1,p2=-1;
	f(i,0,x) if(a[i]<a[x]) p1=i;
	f(i,x+1,n) if(a[i]<a[x]) p2=i;
	if(p1!=-1 && p2!=-1) a1=p1,b=x,c=p2;
}

int main(){
	cin>>t;
	while(t--){
		a1=-1;
		cin>>n;
		f(i,0,n) gett(a[i]);
		f(i,1,n-1)
			calc(i);
		if(a1>=0) cout<<"YES"<<endl<<a1+1<<" "<<b+1<<" "<<c+1<<endl;
		else cout<<"NO"<<endl;
	}
}