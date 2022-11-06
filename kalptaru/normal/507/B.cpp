#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll q,w,e,r,t,y;
	double u;
	cin>>q>>w>>e>>r>>t;
	u=pow((pow((w-r),2)+pow((e-t),2)),0.5);
	u=u/(2*q);
	y=u;
	if(y!=u)
	y++;
	cout<<y;
	return 0;
}