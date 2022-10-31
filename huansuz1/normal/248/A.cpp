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

int n,m,x,y,a,b;

int main(){     
	cin>>n;
	for (int i=1; i<=n; i++)  {
		cin>>x>>y;
		a+=x;
		b+=y;
	}
	if (n-a<a) m+=n-a; else m+=a;
	if (n-b<b) m+=n-b; else m+=b;
	cout<<m;


	return 0;
}