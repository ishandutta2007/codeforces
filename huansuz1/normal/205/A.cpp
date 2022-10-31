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

int n,k, a[123456], z,m,mi=1000000000;

int main(){     
    cin>>n;
    for (int i=0; i<n; i++) {
    	cin>>a[i];
    	if (a[i]<mi) {mi=a[i]; m=i;}
    }
    for (int i=0; i<n; i++)
    	if (a[i]==mi) z++;
    if (z>1) cout<<"Still Rozdil"; else cout<<m+1;



	return 0;
}