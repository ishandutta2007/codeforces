// Hydro submission #6253c25b48f7830132791aed@1649656411171
#include<bits/stdc++.h>
using namespace std;
long long s,a,t[55];
int main()
{
	int i,n;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		if(a<0)
		t[abs(a)+10]++; 
		else t[a]++;
	}
	for(i=1;i<=10;i++)
	s+=t[i]*t[i+10]; 
	s+=(t[0]-1)*t[0]/2; 
	cout<<s;
	return 0;
}