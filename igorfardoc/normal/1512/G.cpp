#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int lp[10000001];
int st[10000001];
ll func[10000001];
int obr[10000001];
vector<int> pr;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    lp[1] = 1;
    func[1] = 1;
    st[1] = 1;
    for(int i = 2; i <= 10000000; i++)
    {
    	if(lp[i] == 0)
    	{
    		lp[i] = i;
    		st[i] = i;
    		func[i] = i + 1;
    		pr.push_back(i);
    	}
    	/*if(i < 10)
    	{
    		cout << i << ' ' << func[i] << endl;
    	}*/
    	for(int j = 0; j < pr.size() && pr[j] <= lp[i] && (ll)pr[j] * i <= 10000000; j++)
    	{
    		lp[pr[j] * i] = pr[j];
    		st[pr[j] * i] = pr[j];
    		func[pr[j] * i] = func[i] * func[pr[j]];
    		if(pr[j] == lp[i] && st[i] != i)
    		{
    			st[pr[j] * i] *= st[i];
    			func[pr[j] * i] = func[i / st[i]] * func[st[i] * pr[j]];
    		}
    		else if(pr[j] == lp[i])
    		{
    			st[pr[j] * i] *= st[i];
    			func[pr[j] * i] = func[i] + pr[j] * i;
    		}
    	}
    }
    for(int i = 10000000; i >= 1; i--)
    {
    	if(func[i] <= 10000000)
    	{
    		obr[func[i]] = i;
    	}
    }
    int t;
    cin >> t;
    while(t--)
    {
    	int n;
    	cin >> n;
    	if(obr[n] == 0)
    	{
    		cout << "-1\n";
    	}
    	else
    	{
    		cout << obr[n] << '\n';
    	}
    }
}