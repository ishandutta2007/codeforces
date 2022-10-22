#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,tot,rt,l,r,b;
int a[1000010];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=(n+1)/2;i>=1;--i){
    	if(i&1)swap(a[i],a[n-i+1]);
	}
    for(int i=1;i<=n;i++)cout<<a[i]<<' ';
    return 0;
}