#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long q,n,d,x,y,w,i;
	cin>>q;
	for(i=1;i<=q;i++)
	{
		cin>>n>>x>>y>>d;
		w=1000000000000007;
		if(abs(y-x)%d==0)
			w=min(w,abs(y-x)/d);
		if((y-1)%d==0)
			w=min(w,(x-1+d-1)/d+(y-1)/d);
		if((n-y)%d==0)
			w=min(w,(n-x+d-1)/d+(n-y)/d);
		if(w==1000000000000007)
			cout<<"-1\n";
		else
			cout<<w<<"\n";
	}
	return 0;
}