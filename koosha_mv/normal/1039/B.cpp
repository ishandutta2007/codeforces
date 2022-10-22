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

ll x,n,k,l,r,mid;
string s;

bool ask(ll l,ll r){
	cout<<l<<" "<<r<<endl;
	cin>>s;
	return s[0]=='Y'; 
}

int main(){
	srand(time(NULL));
	cin>>n>>k;
	l=1,r=n;
	while(1){
		while(l+43<r){
			mid=(l+r)/2;
			if(ask(l,mid)) l=max(l-10,1ll),r=min(mid+10,n);
			else l=max(mid-10,1ll),r=min(r+10,n);
		}
		x=l+(rand()%(r-l+1));
		if(ask(x,x)) return 0;
		l=max(l-10,1ll),r=min(r+10,n);
	}
}