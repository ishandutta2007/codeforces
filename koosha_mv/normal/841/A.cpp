#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=2e5+9;
ll n,k,mx,mark[160];
string s;
int main(){
	cin>>n>>k;
	cin>>s;
	f(i,0,n){
		mark[s[i]]++;
		maxm(mx,mark[s[i]]);
	}
	if(mx>k) cout<<"NO";
	else cout<<"YES";
}