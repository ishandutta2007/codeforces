#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
using namespace std;

const double pi = acos(-1.);

int main()
{
	int n;
	int a,sum=0,mx=-1;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a;
		mx = max(a,mx);
		sum+=a;
	}
	sum-=mx;
	cout << mx-sum+1;
	return 0;
}