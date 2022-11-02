#include<bits/stdc++.h>
using namespace std;
typedef int ll;
string abc="aabbaabb";
ll a;
int main()
{
    cin>>a;
    for(register int i=0;i<a;i++)
    {
    	cout<<abc[i%8];
	}
}