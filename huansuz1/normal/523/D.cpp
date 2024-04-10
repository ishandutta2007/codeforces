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

multiset<long long> ar;     
int n,s,k,z;
long long m,a,b;

int main()
{
scanf("%d %d",&n,&k);


for (int i=1; i<=n; i++){
	scanf("%d %d",&a,&b);
	if (i<=k){
		ar.insert(a+b);
		printf("%I64d\n",a+b);
	}else {
		m=*ar.begin();
		if (m>a) {ar.insert(m+b); printf("%I64d\n",m+b);}else {
			ar.insert(a+b);                                 
			printf("%I64d\n",a+b);
		}
		ar.erase(ar.begin());
	}
}
	
	return 0;
}