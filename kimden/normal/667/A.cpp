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
	int d,h,v,e;
	cin>> d>> h >> v >> e;
	double dh = v*4. / (pi*d*d);
	if(dh>e){
		cout << "YES\n";
		cout << setprecision(9) << ((double)h)/(dh-e);
	}else{
		cout << "NO\n";
	}
	return 0;
}