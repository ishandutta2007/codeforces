#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,s=0,_min=INT_MAX,_max=INT_MIN;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if (d==1)
			_max=max(_max,1900-s);
		else
			_min=min(_min,1899-s);
		s+=c;
	}
	if (_min==INT_MAX) printf("Infinity");
	else if (_max<=_min) printf("%d",_min+s);
	else printf("Impossible");
	return 0;
}