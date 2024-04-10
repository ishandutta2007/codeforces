#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
void die(string S){puts(S.c_str());exit(0);}
int main()
{
	ll n,m,a,b;
	cin>>n>>m>>a>>b;
	if(b==n)
		b=(n+m-1)/m*m;
	a--;
	b--;
	if(b/m==a/m)
		die("1");
	if(b/m==a/m+1)
	{
		if(b%m==m-1&&a%m==0)
			die("1");
		die("2");
	}
	if(b%m==m-1&&a%m==0)
		die("1");
	if(b%m==m-1||a%m==0)
		die("2");
	if(b%m==a%m-1)
		die("2");
	die("3");
	return 0;
}