#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int> > a;
vector<pair<int, int> > res;
vector<int> c;

int now;

void solve(vector<int> & vec, int root)
{
	if(vec.size() == 1)
	{
		res.push_back({root, vec[0]});
		return;
	}
	if(vec.size() == 2)
	{
		res.push_back({root, vec[0]});
		res.push_back({root, vec[1]});
		return;
	}
	vector<pair<int, int> > mass;
	for(int i = 1; i < vec.size(); i++)
	{
		mass.push_back({a[vec[0]][vec[i]], vec[i]});
	}
	sort(mass.begin(), mass.end());
	int nowver = vec[0];
	vector<int> vec1;
	for(int i = 0; i < mass.size(); i++)
	{
		vec1.push_back(mass[i].second);
		if(i == (int)mass.size() - 1 || mass[i + 1].first != mass[i].first)
		{
			int nowver1;
			int maxhere = -1;
			for(int j = 0; j < vec1.size(); j++)
			{
				maxhere = max(maxhere, a[vec1[0]][vec1[j]]);
			}
			if(mass[i].first != mass[(int)mass.size() - 1].first)
			{
				nowver1 = now++;
				c.push_back(mass[i].first);
			}
			else
			{
				nowver1 = root;
			}
			res.push_back({nowver1, nowver});
			if(maxhere == mass[i].first || vec1.size() == 1)
			{
				solve(vec1, nowver1);
			}
			else
			{
				int onemore = now++;
				c.push_back(maxhere);
				solve(vec1, onemore);
				res.push_back({nowver1, onemore});
			}
			nowver = nowver1;
			vec1.clear();
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n;
    cin >> n;
    int max1 = -1;
    a.assign(n, vector<int>(n));
    vector<int> vec(n);
    for(int i = 0; i < n; i++)
    {
    	vec[i] = i;
    	for(int j = 0; j < n; j++)
    	{
    		cin >> a[i][j];
    		max1 = max(max1, a[i][j]);
    	}
    	c.push_back(a[i][i]);
    }
    now = n + 1;
    c.push_back(max1);
    solve(vec, n);
    cout << now << '\n';
    for(int i = 0; i < c.size(); i++)
    {
    	cout << c[i] << ' ';
    }
    cout << '\n';
    cout << n + 1 << '\n';
    for(int i = 0; i < res.size(); i++)
    {
    	cout << res[i].second + 1 << ' ' << res[i].first + 1 << '\n';
    }
}