#include<iostream>
#include <cstdio>
#include<algorithm>
#include<map>
#include<string>
              
#define inf (1<<30) 
#define s second
#define sz 100000
#define f first

using namespace std;

int n,k, a[123456], z,m,b[123456];

int main(){     
    cin>>n;
    for (int i=0; i<n; i++)
    	cin>>a[i];

    for (int i=0; i<n-1; i++)
    	if (a[i]>a[i+1]) { k=i+1; break; }
    for (int i=k; i<n; i++)
    	b[m++]=a[i];

	for (int i=0; i<k; i++)
    	b[m++]=a[i];


    if (k==0) {cout<<0; return 0;}
    sort(a,a+n);
    for (int i=0; i<n; i++)
    	if (a[i]!=b[i]) { cout<<-1; return 0; }
    cout<<n-k;

	return 0;
}