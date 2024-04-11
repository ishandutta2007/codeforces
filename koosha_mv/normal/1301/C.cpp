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
const int N=3e5+9;
ll n,t,m,s,p,t1,t2;
int main(){
	cin>>t;
	f(q,0,t){
		cin>>n>>m;
		s=n-m;
		if(m>=(n/2)+(n%2)){
			cout<<(n*(n+1))/2-s<<endl;
		}
		else{
			p=s/(m+1);
			t1=s-(p*(m+1));
			t2=m+1-t1;
			//cout<<t1<<" "<<t2<<" 8 "<<p<<endl;
			cout<<((n*(n+1))/2)-(t1*((p+1)*(p+2)/2))-(t2*((p*(p+1))/2))<<endl;
		}
	}
}