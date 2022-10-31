// Hydro submission #62579740ac286d0a56ba9261@1649907521455
#include<bits/stdc++.h>
using namespace std;
int s,m[100];
int main()
{
	int n,r,b;
	cin>>n;
	for(b=1;b<=n;b*=10)
	{
		r=(n/b)%10;
		s=s>r?s:r;
		for(int i=1;i<=r;++i)
		m[i]+=b;
	}
	printf("%d\n",s);
	for(;s;--s)
	printf("%d ",m[s]);
	cout<<endl;
	return 0;
}