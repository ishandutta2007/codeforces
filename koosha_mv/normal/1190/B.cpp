#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
ll n,a[100999],k,sum;
string p1="sjfnb",p2="cslnb";
int main(){
	cin>>n;
	f(i,0,n){cin>>a[i];sum+=a[i];}
	sort(a,a+n);
	f(i,0,n-1){
		if(a[i]==a[i+1]){
			k++;
			if(k==2 || (i>0 && a[i]==a[i-1]+1) || a[i]==0){
				cout<<"cslnb";
				return 0;
			}
		}
	}
	if(sum%2==((n*(n-1))/2)%2) cout<<p2;
	else cout<<p1;
}