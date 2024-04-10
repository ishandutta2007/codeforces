#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int k[10];

int main()
{
	int n;
	memset(k,0,sizeof(k));
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int A;
		scanf("%d",&A);
		k[A]++;
	}
	k[1]=max(0,k[1]-k[3]);
	cout << k[4]+k[3]+(k[2]*2+k[1]+3)/4 << endl;
	return 0;
}