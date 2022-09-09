#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int nod (int e, int r)
{
	if (e<r)
		swap (e,r);
	while (r>0)
	{
		e%=r;
		swap (e,r);
	}
	return e;
}
int main()
{
    int n, i, s=0;
	cin>>n;
    for (i=2; i<n; i++)
	{
		int k=n;
		while (k)
		{
			s+=k%i;
			k/=i;
		}
	}
	int k=nod (s, n-2);
	cout<<(s/k)<<'/'<<((n-2)/k);
    return 0;
}