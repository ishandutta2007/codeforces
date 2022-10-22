#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int a1,a2,k1,k2,n,ans;

int main(){
	cin>>a1>>a2>>k1>>k2>>n;
	if(k1>k2){swap(a1,a2);swap(k1,k2);
	}
	cout<<max(0,n-a1*(k1-1)-a2*(k2-1))<<" ";
	ans=0;
	if(n<a1*k1)cout<<(n/k1)<<endl;
	else cout<<a1+(n-a1*k1)/k2<<endl;
}