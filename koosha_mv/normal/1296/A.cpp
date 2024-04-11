#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);

const int N=3e5+9;
ll n,t,a[N],sum,p1,p2;
int main(){
	cin>>t;
	f(q,0,t){
		cin>>n;sum=0,p1=0,p2=0;
		f(i,0,n){
			cin>>a[i];
			sum+=a[i];
			if(a[i]%2==1)
				p2=1;
			else
				p1=1;
		}
		if(sum%2==1 || (p1==1 && p2==1))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}