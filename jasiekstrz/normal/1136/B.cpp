#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;
	cin>>n>>k;
	cout<<3*n+min(k-1,n-k);
	/*if(k==n)
		cout<<3*n;
	else
		cout<<3*n+k-1;*/
	return 0;
}