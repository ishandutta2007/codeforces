#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=200100;
int a[N],n;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	int j=n;
	while (a[j]==a[n])j--;
	cout<<j<<endl;
}