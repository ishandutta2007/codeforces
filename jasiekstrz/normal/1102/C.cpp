#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,x,y,a,w,i;
	cin>>n>>x>>y;
	w=0;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		if(a<=x)
			w++;
	}
	w=(w+1)/2;
	if(x>y)
		cout<<n;
	else
		cout<<w;
	return 0;
}