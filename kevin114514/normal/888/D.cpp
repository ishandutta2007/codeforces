#include<bits/stdc++.h>
using namespace std;
const long long WrongArrangement[5]={1,0,1,2, 9};
const long long        Factories[5]={1,1,2,6,24};
long long C(int n,int k)
{
	long long ans=1;
	for(int i=0;i<k;i++)
		ans*=(n-i);
	ans/=Factories[k];
	return ans;
}
int main()
{
	int n,k;
	cin>>n>>k;
	long long ans=0;
	for(int i=0;i<=k;i++)
		ans+=WrongArrangement[i]*C(n,i);
	cout<<ans<<endl;
}