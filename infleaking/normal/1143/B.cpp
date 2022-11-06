#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char a[100];
int n,d=1,ans;
int power(int a,int b){
	int ans=1;
	for (int i=1;i<=b;i++)ans=ans*a;
	return ans;
}
int main(){
	scanf("%s",a);
	n=strlen(a);
	ans=power(9,n-1);
	for (int i=0;i<n;i++){
		ans=max(ans,d*power(9,n-i-1)*(a[i]-'1'));
		d=d*(a[i]-'0');
	}
	cout<<max(ans,d)<<endl;
}