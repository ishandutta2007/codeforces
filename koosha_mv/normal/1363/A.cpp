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

const int N=5e5+99;

int n,t,f,z,x,a[N];

int main(){
	cin>>t;
	f(q,0,t){
		f=0,z=0;
		ll sum=0;
		cin>>n>>x;
		f(i,0,n){
			cin>>a[i];
			sum+=a[i];
			if(a[i]%2==1) f=1;
			else z=1;
		}
		if(x==n) cout<<(sum%2==1 ? "YES":"NO");
		else{
			if((f && z) || (f && x%2)) cout<<"YES";
			else cout<<"NO";
		}
		cout<<endl;
	}
}