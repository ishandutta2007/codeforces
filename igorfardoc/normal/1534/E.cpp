#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef long long ll;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n, k;
    cin >> n >> k;
    vector<int> dist(n + 1, INF);
    vector<int> prev(n + 1, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(!q.empty())
    {
    	int v = q.front();
    	q.pop();
    	for(int i = 0; i <= k; i++)
    	{
    		if(i > v)
    		{
    			continue;
    		}
    		if(k - i > n - v)
    		{
    			continue;
    		}
    		int u = v + k - 2 * i;
    		if(dist[u] == INF)
    		{
    			dist[u] = dist[v] + 1;
    			prev[u] = v;
    			q.push(u);
    		}
    	}
    }
    if(dist[n] == INF)
    {
    	cout << -1 << endl;
    	return 0;
    }
    int ans = 0;
    vector<int> a1;
    vector<int> a2;
    for(int i = 0; i < n; i++)
    {
    	a2.push_back(i);
    }
    int now = n;
    vector<int> op;
    while(now != 0)
    {
    	op.push_back(now - prev[now]);
    	now = prev[now];
    }
    reverse(op.begin(), op.end());
    for(int i = 0; i < op.size(); i++)
    {
    	int froma1 = (k - op[i]) / 2;
    	int froma2 = k - froma1;
    	//cout << froma1 << ' ' << froma2 << ' ' << a1.size() << ' ' << a2.size() << endl;
    	vector<int> now;
    	cout << "? ";
    	for(int j = 0; j < froma1; j++)
    	{
    		cout << a1[a1.size() - 1] + 1 << ' ';
    		now.push_back(a1[a1.size() - 1]);
    		a1.pop_back();
    	}
    	for(int j = 0; j < froma2; j++)
    	{
    		cout << a2[a2.size() - 1] + 1 << ' ';
    		now.push_back(a2[a2.size() - 1]);
    		a2.pop_back();
    	}
    	cout << endl;
    	int val;
    	cin >> val;
    	ans ^= val;
    	for(int j = 0; j < froma1; j++)
    	{
    		a2.push_back(now[j]);
    	}
    	for(int j = froma1; j < k; j++)
    	{
    		a1.push_back(now[j]);
    	}
    }
    cout << "! " << ans;
}