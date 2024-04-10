#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[10000],b[10000];
void insert(int i, int A[],int len)
{
	for(int j = i+1;j<len;j++)
	{
		A[j] = A[j-1];
	}
	A[i] = 1;
}
int main(){
	int n;
	cin>>n;
	
	for(int i = 0;i<n;i++){
		cin>>a[i];
		b[i] = a[i];
	}
	int cnt = 0;
	for(int i = 1;i<n;i++)
	{
		if(__gcd(a[i],a[i-1]) != 1)
			cnt++;
	}
	cout<<cnt<<endl;
	cout<<a[0]<<" ";
	for(int i = 1;i<n;i++)
	{
		if(__gcd(a[i],a[i-1]) != 1)
			cout<<1<<" ";
		cout<<a[i]<<" ";
	}
	
}