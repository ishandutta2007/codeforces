#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define ll long long
int n,i,x[2],y[2];
char a[MAXN],b[MAXN];
int main()
{
	scanf("%d%s%s",&n,a,b);
	for(i=0;i<n;i++)
	{
		x[a[i]^'0']++;
		if(b[i]=='0')y[a[i]^'0']++;
	}
	cout<<(ll)x[0]*y[1]+(ll)x[1]*y[0]-(ll)y[0]*y[1]<<endl;
	return 0;
}