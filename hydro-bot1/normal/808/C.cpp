// Hydro submission #6231b1c948b57a793469b3e8@1647423946210
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct tea
{
	int v = 0;
	int v2 = 0;
	int index;
}arr[200];
bool cmp1(tea a, tea b)
{
	return a.v > b.v;
}
bool cmp2(tea a, tea b)
{
	return a.index < b.index;
}

int main()
{
	int n,w;
	scanf("%d%d", &n,&w);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i].v);
		arr[i].index = i;
		sum += (arr[i].v + 1) / 2;
	}
	if (sum>w) { cout << "-1"; return 0; }
	sort(arr, arr+ n, cmp1);
	for (int i = 0; i < n; i++)
	{
		arr[i].v2 = (arr[i].v+1)/2;
		w -= arr[i].v2;
	}
	for (int i = 0; i < n; i++)
	{
		if (w >= arr[i].v - arr[i].v2)
		{
			w -= (arr[i].v - arr[i].v2);
			arr[i].v2 = arr[i].v;
			
		}
		else
		{
			arr[i].v2 += w;
			break;
		}
	}
	sort(arr, arr + n,cmp2);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i].v2);
	
	

	return 0;
}