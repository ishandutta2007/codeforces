#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int> > solution;
int a[101];
int k;
int n;
int m;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0;i < n;i++)
		scanf("%d", a+i);
	for (;m < k;m++)
	{
		int smallest = 0, largest = 0;
		for (int i = 0;i < n;i++)
		{
			if (a[i] > a[largest])
				largest = i;
			if (a[i] < a[smallest])
				smallest = i;
		}
		if (a[smallest]+1 >= a[largest])
			break;
		a[largest]--;
		a[smallest]++;
		solution.push_back(make_pair(largest+1, smallest+1));
	}
	int smallest = 0, largest = 0;
	for (int i = 0;i < n;i++)
	{
		if (a[i] > a[largest])
			largest = i;
		if (a[i] < a[smallest])
			smallest = i;
	}
	printf("%d %d\n", a[largest]-a[smallest], m);
	for (unsigned i = 0;i < solution.size();i++)
		printf("%d %d\n", solution[i].first, solution[i].second);
	return 0;
}