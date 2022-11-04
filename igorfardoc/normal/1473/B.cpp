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
    int q;
    cin >> q;
    while(q--)
    {
    	string s1, s2;
    	cin >> s1 >> s2;
    	string s3 = s1;
    	string s4 = s2;
    	int now = 0;
    	bool ok = false;
    	while(min((int)s3.size(), (int)s4.size()) < 3000)
    	{
    		for(; now < min((int)s3.size(), (int)s4.size()); now++)
    		{
    			if(s3[now] != s4[now])
    			{
    				cout << "-1\n";
    				ok = true;
    				break;
    			}
    		}
    		if(ok)
    		{
    			break;
    		}
    		if(s3.size() == s4.size())
    		{
    			cout << s3 << '\n';
    			ok = true;
    			break;
    		}
    		if(s3.size() < s4.size())
    		{
    			s3 += s1;
    		}
    		else
    		{
    			s4 += s2;
    		}
    	}
    	if(!ok)
    	{
    		cout << "-1\n";
    	}
    }
}