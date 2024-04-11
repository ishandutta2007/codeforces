#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=3e5+99;
int n,t,m,x,y,ans2,ans1;
int main(){
	cin>>t;
	f(q,0,t){
		cin>>n>>x>>y;
		if(x>y) swap(x,y);
		ans2=(n-(min(x+y-1,n)));
		ans1=min(max(x+y-n,0),n-1);
		cout<<ans1+1<<" "<<n-ans2<<endl;
	}
}