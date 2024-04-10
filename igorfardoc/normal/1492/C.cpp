#include<bits/stdc++.h>
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
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int nowt = m - 1;
    vector<int> arr;
    for(int i = n - 1; i >= 0; i--)
    {
    	if(nowt < 0)
    	{
    		break;
    	}
    	if(s[i] == t[nowt])
    	{
    		arr.push_back(i);
    		nowt--;
    	}
    }
    reverse(arr.begin(), arr.end());
    int nows = 0;
    int ans = -1;
    for(int i = 0; i < m - 1; i++)
    {
    	while(s[nows] != t[i])
    	{
    		++nows;
    	}
    	arr[i] = nows;
    	++nows;
    	ans = max(ans, arr[i + 1] - arr[i]);
    }
    cout << ans;
}