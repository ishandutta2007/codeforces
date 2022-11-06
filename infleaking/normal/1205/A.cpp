#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=1e6+10;
int a[N],n;
int main(){
	cin>>n;
	if (n&1){
		cout<<"YES\n";
	}
	else {
		cout<<"NO\n";
		return 0;
	}
	for (int i=1;i<=n;i++){
		a[i]=i*2-1;
		a[i+n]=i*2;
		if (i%2==0)swap(a[i],a[i+n]);
	}
	for (int i=1;i<=2*n;i++)printf("%d ",a[i]);
	
}