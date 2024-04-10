#include<bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a,int b)
{
	if(!b)
		return a;
	return gcd(b,a%b);
}
signed main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int m,d,w;
		cin>>m>>d>>w;
		if(min(m,d)==1)
		{
			puts("0");
			continue;
		}
		int Max=min(m,d);
		int a=gcd(d-1,w);
		w/=a;
		int Rem=Max%w,Num=Max/w;
		cout<<Rem*(Num+1)*Num/2ll+(w-Rem)*(Num-1)*Num/2ll<<endl;
	}
	return 0;
}