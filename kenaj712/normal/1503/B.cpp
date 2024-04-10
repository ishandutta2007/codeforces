#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v1;
vector<pair<int,int>> v2;
void solve()
{
    int a;
    cin>>a;
    for(int x=1;x<=a;x++)
        for(int y=1;y<=a;y++)
        {
            if((x+y)%2)
                v1.push_back(make_pair(x,y));
            else
                v2.push_back(make_pair(x,y));
        }
    int t = a*a;
    while(t--)
    {
        int b;
        cin>>b;
        if(b == 1)
        {
            if(v2.empty())
            {
                cout<<3<<" "<<v1.back().first<<" "<<v1.back().second<<'\n';
                cout.flush();
                v1.pop_back();
            }
            else
            {
                cout<<2<<" "<<v2.back().first<<" "<<v2.back().second<<'\n';
                cout.flush();
                v2.pop_back();
            }
        }
        else if(b == 2)
        {
            if(v1.empty())
            {
                cout<<3<<" "<<v2.back().first<<" "<<v2.back().second<<'\n';
                cout.flush();
                v2.pop_back();
            }
            else
            {
                cout<<1<<" "<<v1.back().first<<" "<<v1.back().second<<'\n';
                cout.flush();
                v1.pop_back();
            }
        }
        else
        {
            if(v1.empty())
            {
                cout<<2<<" "<<v2.back().first<<" "<<v2.back().second<<'\n';
                cout.flush();
                v2.pop_back();
            }
            else
            {
                cout<<1<<" "<<v1.back().first<<" "<<v1.back().second<<'\n';
                cout.flush();
                v1.pop_back();
            }
        }

    }
}
int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
    int t;
    t = 1;
    while(t--)
        solve();
	return 0;
}