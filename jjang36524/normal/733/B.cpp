#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int lrdiff[100100];
int lrdifnow;
int main()
{
	int N;
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		int l,r;
		cin >> l >> r;
		lrdiff[i] = l - r;
		lrdifnow += l - r;
	}
	pair<int, int>minbeau = { abs(lrdifnow),0 };
	for (i = 0; i < N; i++)
	{
		minbeau = max(minbeau, { abs(lrdifnow - 2 * lrdiff[i]),i + 1 });
	}
	cout << minbeau.second;
}