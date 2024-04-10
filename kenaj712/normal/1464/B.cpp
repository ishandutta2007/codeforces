#include<bits/stdc++.h>
using namespace std;
#define int long long
int lewo[3];
int prawo[3];
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string d;
    int c1,c2;
    cin>>d>>c1>>c2;
    int mini = 1e18;
    int cost = 0;
    for(auto x:d)
    {
        if(x == '0')
        {
            cost += prawo[1]*c2;
            prawo[0]++;
        }
        else
        {
            cost += prawo[0]*c1;
            prawo[1]++;
        }
    }
    mini = min(mini , cost);
    for(auto x:d)
    {
        if(x == '0')
        {
            lewo[0]++;
            prawo[0]--;
        }
        else if(x == '1')
        {
            lewo[1]++;
            prawo[1]--;
        }
        else
        {
            prawo[1]--;
            cost -= lewo[0]*c1;
            cost -= prawo[0]*c2;
            cost += lewo[1]*c2;
            cost += prawo[1]*c1;
            lewo[0]++;
        }
        mini = min(mini,cost);
    }
    lewo[0]=0;
    lewo[1]=0;
    cost = 0;
    for(auto x:d)
    {
        if(x == '0' || x == '?')
        {
            cost += prawo[1]*c2;
            prawo[0]++;
        }
        else
        {
            cost += prawo[0]*c1;
            prawo[1]++;
        }
    }
    mini = min(mini , cost);
    for(auto x:d)
    {
        if(x == '0')
        {
            lewo[0]++;
            prawo[0]--;
        }
        else if(x == '1')
        {
            lewo[1]++;
            prawo[1]--;
        }
        else
        {
            prawo[0]--;
            cost += lewo[0]*c1;
            cost += prawo[0]*c2;
            cost -= lewo[1]*c2;
            cost -= prawo[1]*c1;
            lewo[1]++;
        }
        mini = min(mini,cost);
    }
    cout<<mini;
	return 0;
}