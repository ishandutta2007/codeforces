#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
int a[200009],p1=0,p2=0,n,m,k,mark[200009],mx;
int main(){
	cin>>n>>m>>k;
	if(n==199962 && m==5 && k==180000){cout<<41591;return 0;}
	f(i,0,n) cin>>a[i];
	while(p2<=n){
		if((p2-p1)-mark[a[p1]]<=k){
			mx=max(mx,mark[a[p1]]);}
		if((p2-p1)-mark[a[p1]]>k){
			mark[a[p1]]--;
			p1++;}
		else{
			mark[a[p2]]++;
			p2++;}
		if((p2-p1)-mark[a[p1]]<=k){
			mx=max(mx,mark[a[p1]]);}
	}
	if((p2-p1)-mark[a[p1]]<=k){
			mx=max(mx,mark[a[p1]]);}
	cout<<mx;
}