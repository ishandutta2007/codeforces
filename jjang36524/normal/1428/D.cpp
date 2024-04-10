#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;
#define int long long
int arr[100100];
int mat[100100];
int fp[100100];
stack<int>m2;
stack<int>m3;
vector<pair<int, int>>t;
signed main()
{
	int N,K;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		fp[i] = N - i;
		cin >> arr[i];
		if (arr[i] == 1)
		{
			if (m2.size())
			{
				auto a = m2.top();
				m2.pop();
				t.push_back({ i + 1,fp[a] });
				mat[a]++;
			}
			else if (m3.size())
			{
				auto a = m3.top();
				m3.pop();
				t.push_back({ i + 1,fp[a] });
				t.push_back({ i + 1,fp[i] });
				mat[a]++;
			}
			else
			{
				t.push_back({ i + 1,fp[i] });
			}
		}
		if (arr[i] == 2)
		{
			if (m3.size())
			{
				auto a = m3.top();
				m3.pop();
				t.push_back({ i + 1,fp[a] });
				mat[a]++;
			}
			t.push_back({ i + 1,fp[i] });
			m2.push(i);
		}
		if (arr[i] == 3)
		{
			if (m3.size())
			{
				auto a = m3.top();
				m3.pop();
				t.push_back({ i + 1,fp[a] });
				mat[a]++;
				
			}
			t.push_back({ i + 1,fp[i] });
			m3.push(i);
		}
	}
	for (i = 0; i < N; i++)
	{
		if (arr[i] > 1 && !mat[i])
		{
			cout << -1;
			return 0;
		}
	}
	cout << t.size() << '\n';
	for (i = 0; i < t.size(); i++)
	{
		cout << N+1-t[i].second << ' ' << t[i].first << '\n';
	}
}