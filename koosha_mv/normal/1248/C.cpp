#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[100002],s1,s2, m=1000000007;
ll p(int x){
	a[0]=2;
	a[1]=2;
	for(int i=1;i<x;i++){
		a[i]=a[i-1]+a[i-2];
		a[i]=a[i]%m;	}}
int main(){
	cin>>s1>>s2;
	p(max(s1,s2)+1);
	cout<<(a[s1]+a[s2]-2)%m;
}