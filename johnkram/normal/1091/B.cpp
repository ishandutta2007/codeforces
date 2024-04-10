#include<bits/stdc++.h>
using namespace std;
int n,i;
pair<int,int> a[1005],b[1005];
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
	for(i=1;i<=n;i++)cin>>b[i].first>>b[i].second;
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	cout<<a[1].first+b[n].first<<' '<<a[1].second+b[n].second<<endl;
	return 0;
}