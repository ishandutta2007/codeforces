#include<algorithm>
#include<iostream>
#include<string>
 
using namespace std;
int main()
{
	long long a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	if (a+b+c+d+e==0) cout<<-1; else
		if ((a+b+c+d+e)%5==0) cout<<(a+b+c+d+e)/5; else cout<<-1; 

return 0;
}