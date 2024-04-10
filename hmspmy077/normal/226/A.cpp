#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

long long cal(long long i,long long j,long long mo)
{
	if (j==1) return i;
	if (j%2==1) return i*cal(i,j-1,mo)%mo;
	long long k=cal(i,j/2,mo);
	return k*k%mo;
}

int main()
{
	#ifdef LOCAL_TEST
		freopen("a.in","r",stdin);
		freopen("a.out","w",stdout);
	#endif
	long long n,mo;
	cin>>n>>mo;
	cout<<(cal(3,n,mo)-1+mo)%mo<<endl;
	return 0;
}