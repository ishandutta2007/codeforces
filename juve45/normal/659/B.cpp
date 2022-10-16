#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>

using namespace std;

vector <string> v;
priority_queue <pair <int, int> > p[10009];
vector <pair<int,int> > sol;
string s;
int nr=1;
int n, t;
int main()
{
    cin>>n>>t;
    int k1, k2;
    for(int i=1; i<=n; i++)
    {
        cin>>s>>k1>>k2;
        v.push_back(s);
        p[k1].push({k2, nr});
        nr++;
    }

    for(int i=1; i<=t; i++)
    {
        pair<int, int> a=p[i].top();
        p[i].pop();
        pair<int, int> b=p[i].top();
        p[i].pop();
            if(!p[i].empty())
            {
                pair<int, int> c=p[i].top();
                if(c.first==b.first)
                {
                    sol.push_back({-1, -1});
                    continue;
                }
            }
            sol.push_back({a.second, b.second});
    }

        for(int i=0;i<t;i++)
        {
            if(sol[i].first==-1) cout<<"?\n";
            else cout<<v[sol[i].first-1]<<' '<<v[sol[i].second-1]<<'\n';
        }

    return 0;
}