#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int l[110];
int r[110];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k,i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>l[i]>>r[i];
	cin>>k;
	i=1;
	while((k>r[i])&&(i<=n))
	{
		i++;
	}
	cout<<n-i+1;
	return 0;
}