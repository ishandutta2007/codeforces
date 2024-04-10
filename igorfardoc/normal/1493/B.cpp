#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int h, m;

unordered_map<int, int> d;

bool validrev(int h1, int m1)
{
	if(d[h1 / 10] == -1 || d[h1 % 10] == -1 || d[m1 / 10] == -1 || d[m1 % 10] == -1)
	{
		return false;
	}
	int h2 = d[m1 % 10] * 10 + d[m1 / 10];
	int m2 = d[h1 % 10] * 10 + d[h1 / 10];
	if(h2 < h && m2 < m)
	{
		return true;
	}
	return false;
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
    d[0] = 0;
    d[1] = 1;
    d[2] = 5;
    d[3] = -1;
    d[4] = -1;
    d[5] = 2;
    d[6] = -1;
    d[7] = -1;
    d[8] = 8;
    d[9] = -1;
    int t;
    cin >> t;
    while(t--)
    {
    	cin >> h >> m;
    	int h1 = 0;
    	int m1 = 0;
    	char c;
    	cin >> c;
    	h1 += (c - '0') * 10;
    	cin >> c;
    	h1 += (c - '0');
    	cin >> c;
    	cin >> c;
    	m1 += (c - '0') * 10;
    	cin >> c;
    	m1 += (c - '0');
    	while(!validrev(h1, m1))
    	{
    		//cout << h1 << ' ' << m1 << endl;
    		m1 += 1;
    		if(m1 == m)
    		{
    			m1 = 0;
    			h1 += 1;
    			h1 %= h;
    		}
    	}
    	cout << h1 / 10 << h1 % 10 << ':' << m1 / 10 << m1 % 10 << '\n';
    }
}