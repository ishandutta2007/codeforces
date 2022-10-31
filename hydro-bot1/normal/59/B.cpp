// Hydro submission #6247fb4e0bc575b66aa58acf@1648884559941
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,s=0,a=101;
	cin>>n;
	while(n--)
	{
		cin>>m;
		s+=m;
		if(m%2&&m<a) a=m;
	}
	if(s%2) printf("%d\n",s);
	else if(a==101) printf("0\n");
	else printf("%d\n",s-a);
	return 0;
}