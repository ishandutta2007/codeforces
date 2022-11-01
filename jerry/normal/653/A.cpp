#include <bits/stdc++.h>
using namespace std;

int arr[55], n;

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%d", arr+i);
	for (int i = 0;i < n;i++) for (int j = i+1;j < n;j++) for (int k = j+1;k < n;k++)
	{
		set<int> v;
		v.insert(arr[i]);
		v.insert(arr[j]);
		v.insert(arr[k]);
		if (v.size() == 3 && *v.begin()+2 == *v.rbegin())
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}