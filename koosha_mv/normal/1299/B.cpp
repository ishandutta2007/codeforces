#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=3e5+99;
ll n,a[N][2];
int main(){
	cin>>n;
	f(i,0,n)
		Get(a[i][0],a[i][1]);
	f(i,0,n/2){
		if(a[i][0]-a[i+1][0]!=a[(i+(n/2)+1)%n][0]-a[i+(n/2)][0] || a[i][1]-a[i+1][1]!=a[(i+(n/2)+1)%n][1]-a[i+(n/2)][1] || n%2==1){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
}