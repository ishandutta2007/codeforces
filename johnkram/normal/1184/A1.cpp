#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
int main()
{
	cin>>n;
	if(n>3&&(n&1))cout<<1<<' '<<(n-3>>1)<<endl;
	else puts("NO");
	return 0;
}