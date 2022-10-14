#include <bits/stdc++.h>
using namespace std;
int n,i,x,t,c,f,a[1<<18],l[1<<19];
signed main() {
	for(i=(cin>>n,n);i--;){cin>>a[i];c = ++l[a[i]]>l[c]?a[i]:c;}
	for(x=101;x--;)if(x^c){fill(l,l+2*n,-2);l[n]=n;for(t=n,i=n;i--;) {
	t+=(a[i]==c)-(a[i]==x);if(l[t]^-2)f=max(f,(l[t]-i));else l[t]=i;}}
	cout << f;
}