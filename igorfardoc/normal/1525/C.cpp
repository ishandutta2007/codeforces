#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ans, ans2, pos;
vector<char> a;
vector<pair<pair<int, char>, int>> b;
int n, m;

void do_for(int mod)
{
	vector<int> st;
	for(int i = 0; i < n; i++)
	{
		if(pos[i] % 2 != mod)
		{
			continue;
		}
		if(a[i] == 'R' || st.empty() || a[st[st.size() - 1]] == 'L')
		{
			st.push_back(i);
		}
		else
		{
			int len = pos[i] - pos[st[st.size() - 1]];
			ans[i] = len / 2;
			ans[st[st.size() - 1]] = len / 2;
			st.pop_back();
		}
	}
	int last1 = -1;
	int last2 = -1;
	int n1 = st.size();
	for(int i = 0; i < (int)st.size() / 2; i++)
	{
		if(a[st[2 * i]] != 'L' || a[st[2 * i + 1]] != 'L')
		{
			if(a[st[2 * i]] == 'L')
			{
				last1 = 2 * i;
			}
			break;
		}
		int fir = pos[st[i * 2]];
		int sec = pos[st[i * 2 + 1]];
		int ans1 = fir + (sec - fir) / 2;
		ans[st[i * 2]] = ans1;
		ans[st[i * 2 + 1]] = ans1;
	}
	for(int i = (int)st.size() - 2; i >= 0; i -= 2)
	{
		if(a[st[i]] != 'R' || a[st[i + 1]] != 'R')
		{
			if(a[st[i + 1]] == 'R')
			{
				last2 = i + 1;
			}
			break;
		}
		int fir = pos[st[i]];
		int sec = pos[st[i + 1]];
		int ans1 = m - sec + (sec - fir) / 2;
		ans[st[i]] = ans1;
		ans[st[i + 1]] = ans1;
	}
	if(last1 != -1 && last2 != -1)
	{
		int ans1 = (2 * m - (pos[st[last2]] - pos[st[last1]])) / 2;
		ans[st[last1]] = ans1;
		ans[st[last2]] = ans1;
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
    int t;
    cin >> t;
    while(t--)
    {
    	cin >> n >> m;
    	ans.assign(n, -1);
    	a.resize(n);
    	pos.resize(n);
    	b.resize(n);
    	ans2.resize(n);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> b[i].first.first;
    	}
    	for(int i = 0; i < n; i++)
    	{
    		cin >> b[i].first.second;
    		b[i].second = i;
    	}
    	sort(b.begin(), b.end());
    	for(int i = 0; i < n; i++)
    	{
    		a[i] = b[i].first.second;
    		pos[i] = b[i].first.first;
    	}
    	do_for(0);
    	do_for(1);
    	for(int i = 0; i < n; i++)
    	{
    		ans2[b[i].second] = ans[i];
    	}
    	for(int i = 0; i < n; i++)
    	{
    		cout << ans2[i] << ' ';
    	}
    	cout << '\n';
    }
}