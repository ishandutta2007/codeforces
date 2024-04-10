// Hydro submission #61e167b4920a279b87ec16c0@1642162101539
#include<bits/stdc++.h>
using namespace std;
int main()
{
int t;
int a,b,c;
cin>>t;
    while(t--)
    {
    	cin>>a>>b>>c;
    	if((b*2-a)%c==0&&(b*2-a)/c>0||(b*2-c)%a==0&&(b*2-c)/a>0||(a+c)%2==0&&(a+c)/2%b==0&&(a+c)/2/b>0)
    	cout<<"YES"<<'\n';
    	else
    	cout<<"NO"<<'\n';
	}
	return 0;
}