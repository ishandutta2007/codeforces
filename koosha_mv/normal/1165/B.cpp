#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
int ans,n,a[200009];
int main(){
	cin>>n;
	f(i,0,n){
		cin>>a[i];
	}
	sort(a,a+n);
	int p1=0;
	while(p1<n){
		if(a[p1]>ans){
			ans++;
		}
		p1++;
	}
	cout<<ans;
}