#include <bits/stdc++.h>
using namespace std;

double arr[255];
const int n = 250;

void slv()
{
	for (int i = 0;i < n;i++) scanf("%lf", arr+i);
	double mean = 0;
	for (int i = 0;i < n;i++) mean += arr[i];
	mean /= n;
	double variance = 0;
	for (int i = 0;i < n;i++) variance += (arr[i]-mean)*(arr[i]-mean);
	variance /= n;
	if (0.7*variance <= mean)
		printf("poisson\n");
	else printf("uniform\n");
}

int main()
{
	int v; scanf("%d", &v);
	while (v--) slv();
	return 0;
}