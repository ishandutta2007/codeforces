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
    int t;
    cin >> t;
    vector<int> st = {2};
    while(true)
    {
    	int here = st[st.size() - 1];
    	here *= 2;
    	if(here > 1000000000)
    	{
    		break;
    	}
    	st.push_back(here);
    }
    while(t--)
    {
    	int n;
    	cin >> n;
    	if(n % 2 == 1)
    	{
    		cout << "Bob\n";
    		continue;
    	}
    	bool ok = false;
    	for(int i = 0; i < st.size(); i++)
    	{
    		if(st[i] == n)
    		{
    			if(i % 2 == 0)
    			{
    				cout << "Bob\n";
    			}
    			else
    			{
    				cout << "Alice\n";
    			}
    			ok = true;
    			break;
    		}
    	}
    	if(!ok)
    	{
    		cout << "Alice\n";
    	}
    }
}