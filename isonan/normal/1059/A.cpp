#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n,t[100001],l[100001],L,a,tot;
int main(){
	cin>>n>>L>>a;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>l[i];
		tot+=(t[i]-t[i-1]-l[i-1])/a;
	}
	tot+=(L-(t[n]+l[n]))/a;
	cout<<tot;
}