#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define ll long long int

using namespace std;

vector<double> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(10)<<fixed;
	int q,pt=1,el=1,t,len;
	double sum=0,temp,x;
	v.push_back(0);
	len = 1;
	cin>>q;
	while(q--)
	{
		cin>>t;
		if(t == 1)
		{
			cin>>x;
			temp = (sum + x)/el;
			while(pt < len && (sum+v[pt]+x)/(el+1) < temp)
			{
				temp = (sum+v[pt]+x)/(el+1);
				sum += v[pt];
				el++;
				pt++;
			}
			v.push_back(x);
			len++;
		}
		else
		{
			cout << x-temp<<"\n";
		}
	}
	return 0;
}