#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int n,x[1234],y[1234],m,s,p,ans1,ans2;

int main(){
cin>>n;
for (int i=0; i<n; i++){
cin>>x[i]>>y[i];
if (x[i]<y[i]) swap(x[i],y[i]);
if (m<x[i]){m=x[i]; p=y[i];}
s+=y[i];
}

ans1=s*m;
for (int i=0; i<n; i++){
for (int j=i; j<n; j++)
if (x[i]<x[j]) { swap(x[i],x[j]); swap(y[i],y[j]); } else
if (x[i]==x[j] && y[i]<y[j]) swap(y[i],y[j]);
}

for (int i=0; i<n; i++){
	s-=y[i];
	s+=x[i];
	ans2=0;
	if (p<y[i]) p=y[i];
	if (p>x[i+1]) ans2=(p*s); else ans2=(x[i+1]*s);
	ans1=min(ans2,ans1);
}
cout<<ans1;
}