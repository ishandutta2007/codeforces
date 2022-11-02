#include <cstdio>
#include <vector>

using namespace std;

int n;
int x[500000];
bool X[1000001];
vector<int> option;
vector<int> solution;

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d", x+i);
		X[x[i]] = true;
	}
	for (int i = 0;i <= 500000;i++) if (!X[i] && !X[1000001-i])
		option.push_back(i);
	for (int i = 0;i < n;i++) if (X[x[i]])
	{
		X[x[i]] = false;
		if (X[1000001-x[i]])
		{
			X[1000001-x[i]] = false;
			solution.push_back(option.back());
			solution.push_back(1000001-option.back());
			option.pop_back();
		} else
			solution.push_back(1000001-x[i]);
	}
	printf("%d\n", solution.size());
	for (unsigned i = 0;i < solution.size();i++)
		printf("%d\n", solution[i]);
	return 0;
}