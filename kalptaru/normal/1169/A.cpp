#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	int n,a,b,x,y;
 	bool flag1=1,flag2=1,flag=0;
 	cin>>n>>a>>x>>b>>y;
 	if (a==b){cout<<"YES";return 0;}
 	while(flag1 && flag2)
 	{
 		a+=1;
 		b-=1;
 		if(a>n)a=1;
 		if(b==0)b=n;
 		if(b==y)flag2=0;
 		if(a==x)flag1=0;
 		if (a==b){cout<<"YES";return 0;}
	}
	cout<<"NO";
	return 0;
}