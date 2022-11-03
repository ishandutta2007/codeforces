#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n,a,s=0,s1=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		s = s | a;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		s1 = s1 | a;
	}
	printf("%d",s+s1);
	return 0;
}