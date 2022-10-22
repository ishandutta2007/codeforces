#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
ll a,b,c,d,e,f,n;
int main(){
	cin>>a>>b>>c>>d>>e>>f;
	if(e>f){
		n=min(a,d);
		d-=n;
		cout<<(n*e)+(min(b,min(c,d)))*f;
	}
	else{
		n=min(b,min(c,d));
		d-=n;
		cout<<n*f+min(d,a)*e;
	}
}