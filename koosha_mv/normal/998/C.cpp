#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
ll n,x,y,c;
string s;
int main(){
	cin>>n>>x>>y;
	cin>>s;
	f(i,0,n){
		if(s[i]=='0' && (i==0 || s[i-1]=='1')){
			c++;
		}
	}
	if(c==0){cout<<0;return 0;}
	if(x<y)
		cout<<c*x-x+y;
	else
		cout<<c*y;
}