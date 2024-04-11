#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
int n,m,p1,p2,mx=-1000000,andis1=-1,andis2=-1,a[200009],b[200009];
int main(){
	cin>>n;
	f(i,0,n) cin>>a[i];
	cin>>m;
	f(i,0,m) cin>>b[i];
	sort(a,a+n);sort(b,b+m);b[m]=1e9;
	p1=0,p2=0;
	while(p1<=n && p2<=m){
		if(b[p2]>=a[p1]){
			if((n-p1)-(m-p2)>mx){
				mx=(n-p1)-(m-p2),andis1=p1,andis2=p2;
			}
			p1++;
		}
		else p2++;
	}
	if(0>mx) cout<<n*2<<":"<<m*2;
	else cout<<n*3-andis1<<":"<<m*3-andis2;
}