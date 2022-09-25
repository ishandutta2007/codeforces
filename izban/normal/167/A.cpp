#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long




ll n,a,d;
ll t[100100], v[100100];
double maxt=0;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> a >> d;
	for (int i=0; i<n; i++) {
		cin >> t[i] >> v[i];
		double t1=min(sqrt((double)2*d/a),(double)v[i]/a);
		double s=a*t1*t1/2;
		t1+=(d-s)/v[i];
		t1+=t[i];
		t1=max(t1,maxt);
		maxt=max(t1,maxt);
		printf("%.10lf\n",t1);
	}

	return 0;
}