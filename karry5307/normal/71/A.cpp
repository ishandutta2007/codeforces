#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
string str;
ll cnt;
int main()
{
    cin>>cnt;
    for(register int i=0;i<cnt;i++)
    {
    	cin>>str;
    	if(str.length()>10)
    	{
    		cout<<str[0]<<str.length()-2<<str[str.length()-1]<<endl;
		}
		else
		{
			cout<<str<<endl;
		}
	}
}