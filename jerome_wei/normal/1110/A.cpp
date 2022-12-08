#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
int k,n,b[N];

int main()
{
	cin>>k>>n;
	int tmp=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=n;i;i--){
		ans+=tmp*b[i]%2;
		ans%=2;
		tmp=tmp*k%2;
	}
	if(ans==0)cout<<"even\n";
	else cout<<"odd\n";
}