#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;

int n,t,a[234567],m,q[234567];
long long qq[234567],s;
double c,re[234567],ap[234567],er[234567],me[234567];



int main()
{
	cin>>n>>t>>c;
	for (int i=1; i<=n; i++)  {
		cin>>a[i];             
		s+=a[i];
		qq[i]=s;	
	}
	cin>>m;
	for (int i=1; i<=m; i++){              
		cin>>q[i];  
		re[i]=(qq[q[i]]-qq[q[i]-t]+0.0)/t;
	}

	
		for (int j=1; j<=n; j++)
			me[j]=(me[j-1]+((a[j]+0.0)/t))/c;

		for (int i=1; i<=m; i++)
			er[i]=abs(me[q[i]]-re[i])/re[i];
	 for (int i=1; i<=m; i++)
	 	printf("%.6lf %.6lf %.6lf\n",re[i],me[q[i]],er[i]);
				


	return 0;
}