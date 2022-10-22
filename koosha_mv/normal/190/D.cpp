#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
map <int,int> mark;
ll n,k,a[400009],p1=0,p2=0,sum;
int main(){
	cin>>n>>k;
	f(i,0,n) cin>>a[i];
	while(p1<n){
		if(p2<n && mark[a[p2]]<k-1){ mark[a[p2]]++,p2++;}
		else{sum+=p2-p1;mark[a[p1]]--;p1++;}
	}
	cout<<n*(n+1)/2-sum;
}