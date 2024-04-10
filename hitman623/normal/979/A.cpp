/*****Enigma27*****/
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pll         pair<ll int,ll int>
#define vll          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
#define ios	    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
ll n,i,j,k,l,sum=0,flag=0,t,a[100005],ans=0;
string s;
ll f(ll n){
	if(n==1) return 0;
	if(n&1) return n;
	return n/2;
}
int main()
{
	ios
	cin>>n;
	cout<<f(n+1)<<endl;
	
	return 0;
}