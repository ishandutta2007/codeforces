#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
int mx,m,a[500009],p1,p2,mark[1000099],n,k,l1,l2;
int main(){
	cin>>n>>k;
	f(i,0,n){
		cin>>a[i];
	}
	while(p2<n){
		if(m<k || mark[a[p2]]>=1){
			if(mark[a[p2]]==0)
				m++;
			mark[a[p2]]++;
			p2++;
			if(p2-p1>mx){
				mx=p2-p1;
				l1=p1+1;
				l2=p2;
			}
		}
		else{
			mark[a[p1]]--;
			if(mark[a[p1]]==0){
				m--;
			}
			p1++;
		}
	}
	cout<<l1<<" "<<l2;
}