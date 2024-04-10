#include <iostream>
#include <queue>
#include <set>
#include <vector>

#define x first
#define y second

using namespace std;

typedef pair<int, pair<int, int> > pi;
priority_queue <pi> pq;
multiset <int> s;
vector <int> v[1004];
vector <pair<int, int> > ann;
int n, k, x, sum, ans;

int main()
{
    cin>>n;
    pi a;
    for(int i=1; i<=n; i++)
    {
        cin>>a.y.x>>a.x;
        a.y.y=i;
        pq.push(a);
    }
    cin>>k;
    for(int i=1; i<=k; i++)
    {
        cin>>x;
        v[x].push_back(i);
        s.insert(x);
    }

    while(!pq.empty() && !s.empty())
    {
        a=pq.top();
        pq.pop();
        if(s.lower_bound(a.y.x)!=s.end())
        {
            int gg=*s.lower_bound(a.y.x);
            sum+=a.x;
            ann.push_back(make_pair(v[gg][v[gg].size()-1], a.y.y));
            v[gg].pop_back();
            s.erase(s.lower_bound(a.y.x));
            ans++;

        }

    }
cout<<ans<<' '<<sum<<'\n';
for(int i=0;i<ans;i++)
    cout<<ann[i].y<<' '<<ann[i].x<<'\n';

    return 0;
}