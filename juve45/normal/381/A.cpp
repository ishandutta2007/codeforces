#include <iostream>

using namespace std;

int n, a[1001];
int ans[3];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	int player=0;
	for(int j=n, i=1; j>=i;)
	{
		if(a[j]>a[i])
			ans[player]+=a[j], j--;
		else ans[player]+=a[i], i++;
		player^=1;
	}
	cout<<ans[0]<<' '<<ans[1]<<'\n';

}