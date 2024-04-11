#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef double ld;
typedef long long li;

void solve();
int main()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#endif
	int t=1;
	while (t--)
		solve();
	return 0;
}

//#define int li

double dp1[10050][300], dp2[10050][300];
const int C=3200;

double end1[300500], end2[300500];

void solve()
{
	int hp1, hp2, l1, r1, l2, r2;
	double p1, p2;
	int dt1, dt2;
	cin>>hp1>>dt1>>l1>>r1>>p1;
	cin>>hp2>>dt2>>l2>>r2>>p2;

	if (p1>99.5)
	{
		printf ("0.000000");
		return;
	}
	if (p2>99.5)
	{
		printf ("1.00000000");
		return;
	}

	p1/=100.0;
	p2/=100.0;

	double z1=(double)(r1-l1+1);
	z1=(1.0-p1)/z1;
	double z2=(double)(r2-l2+1);
	z2=(1.0-p2)/z2;

	dp1[0][hp2]=1.0;
	for (int w=0; w<C; w++)
		for (int h=1; h<=hp2; h++)
		{
			dp1[w+1][h]+=p1*dp1[w][h];
			for (int d=l1; d<=r1; d++)
				dp1[w+1][max(0, h-d)]+=dp1[w][h]*z1;
		}

	dp2[0][hp1]=1.0;
	for (int w=0; w<C; w++)
		for (int h=1; h<=hp1; h++)
		{
			dp2[w+1][h]+=p2*dp2[w][h];
			for (int d=l2; d<=r2; d++)
				dp2[w+1][max(0, h-d)]+=dp2[w][h]*z2;
		}

	
	for (int i=1; i<=C; i++)
		end1[(i-1)*dt1]=dp1[i][0], end2[(i-1)*dt2]=dp2[i][0];

	double pref=0.0;
	double ans=0.0;

	for (int i=0; i<=C*30; i++)
	{
		ans+=end1[i]*(1-pref);
		pref+=end2[i];
	}

	printf ("%.10lf", ans);
}