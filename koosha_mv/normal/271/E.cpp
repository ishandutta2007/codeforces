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
const int N=1e5+9,e=2e8;
ll n,m,a[N],ans,b[N],ans1,p;
int main(){
	cin>>n>>m;
	f(i,0,n){
		get(a[i]);a[i]--;
		while(a[i]%2==0) a[i]/=2;
		if(i==0) ans=a[i];
		ans=__gcd(ans,a[i]);
	}
	for(int i=1;i*i<=ans;i++){
		if(ans%i==0){
			p=i;
			while(p<m){
				ans1+=m-p;
				p*=2;
			}
			if(i*i!=ans){
				p=ans/i;
				while(p<m){
					ans1+=m-p;
					p*=2;
				}
			}
		}
	}
	cout<<ans1;
}