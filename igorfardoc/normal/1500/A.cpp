#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxa = 5000000;

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
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i];
    }
    vector<vector<int> > ch(maxa + 1);
    for(int i = 0; i < n; i++)
    {
    	ch[a[i]].push_back(i);
    }
    vector<int> ids;
    for(int i = 1; i < maxa + 1; i++)
    {
    	if(ch[i].size() > 1)
    	{
    		ids.push_back(i);
    	}
    	if(ch[i].size() > 3)
    	{
    		cout << "YES\n";
    		for(int j = 0; j < 4; j++)
    		{
    			cout << ch[i][j] + 1 << ' ';
    		}
    		return 0;
    	}
    }
    if(ids.size() > 1)
    {
    	cout << "YES\n";
    	int id1 = ids[0];
    	int id2 = ids[1];
    	cout << ch[id1][0] + 1 << ' ' << ch[id2][0] + 1 << ' ' << ch[id1][1] + 1 << ' ' << ch[id2][1] + 1;
    	return 0;
    }
    if(ids.size() == 1)
    {
    	int ch1 = ids[0];
    	for(int i = 0; i < n; i++)
    	{
    		if(a[i] == ch1)
    		{
    			continue;
    		}
    		if(2 * ch1 - a[i] <= 0 || 2 * ch1 - a[i] > maxa)
    		{
    			continue;
    		}
    		if(ch[2 * ch1 - a[i]].size() > 0)
    		{
    			cout << "YES\n";
    			cout << ch[ch1][0] + 1 << ' ' << ch[ch1][1] + 1 << ' ' << i + 1 << ' ' << ch[2 * ch1 - a[i]][0] + 1;
    			return 0;
    		}
    	}
    	vector<int> anew;
    	for(int i = 0; i < n; i++)
    	{
    		if(a[i] != ch1 || i == ch[ch1][0])
    		{
    			anew.push_back(a[i]);
    		}
    		else
    		{
    			anew.push_back(-1);
    		}
    	}
    	a = anew;
    }
    if(n < 4)
    {
    	cout << "NO";
    	return 0;
    }
    vector<pair<int, int> > sums(2 * maxa + 1, {-1, -1});
    for(int i = 0; i < n; i++)
    {
    	for(int j = i + 1; j < n; j++)
    	{
    		if(a[i] == -1 || a[j] == -1)
    		{
    			continue;
    		}
    		int sum1 = a[i] + a[j];
    		if(sums[sum1].first != -1)
    		{
    			cout << "YES\n";
    			cout << i + 1 << ' ' << j + 1 << ' ' << sums[sum1].first + 1 << ' ' << sums[sum1].second + 1;
    			return 0;
    		}
    		sums[sum1] = {i, j};
    	}
    }
    cout << "NO";
}