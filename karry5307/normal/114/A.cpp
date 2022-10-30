#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll base,val,res,exponent; 
int main()
{
	cin>>base>>val;
	res=base;
	for(register int i=0;res<val;i++)
	{
		exponent++;
		res*=base;
	}
	val==res?cout<<"YES"<<endl<<exponent:cout<<"NO";
}