#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#define int long long
using namespace std;
vector<int>li[51];
vector<int>l[5000];
int c;
int N, K;
string s;
void dfs(int n)
{
	while (l[n].size())
	{
		int i = l[n].size() - 1;
		int r = l[n][i];
		l[n].pop_back();
		s.push_back((n % N) + 'a');
		dfs(r);
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int  C;
	cin >> C >> N;
	K = 2;
	int RN = 1;
	int i;
	for (i = 1; i < K; i++)
	{
		RN *= N;
	}
	for (i = 0; i < RN * N; i++)
	{
		l[i % RN].push_back(i / N);
	}
	dfs(0);
	for (i = 0; i < C; i++)
	{
		cout << s[i % s.size()];
	}
}