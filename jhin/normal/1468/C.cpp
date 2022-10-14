#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const long long INF=1e18+10;
const int inf=1e9+10,dx[]= {0,0,1,-1,1,-1,1,-1},dy[]= {1,-1,0,0,1,1,-1,-1};
ll MOD=1e9+7;
double eps=1e-11;
//ld eps=1e-7,pi=acos(-1);

#define fi first
#define se second
#define be(x) x.begin(),x.end()
#define Last(x) (*(--x.end()))

int t,m,x,id=0;

vector<int> ans;
int main()
{
ios::sync_with_stdio(0);
set<pair<int,int> > fifo,money;
cin>>t;
while(t--)
{
    cin>>x;

    if(x == 1)
    {
        cin>>m;
        ++id;
        fifo.insert({id,-m});
        money.insert({-m,id});
    }
    else if(x == 2)
    {
        auto it = *fifo.begin();
        int id = it.first;
        int m = it.second;
        fifo.erase(make_pair(id,m));
        money.erase(make_pair(m,id));

        ans.push_back(id);
    }
    else if(x == 3)
    {
        auto it = *money.begin();
        int m = it.first;
        int id = it.second;
        fifo.erase(make_pair(id,m));
        money.erase(make_pair(m,id));

        ans.push_back(id);
    }
}

for(auto a:ans)
    cout<<a<<"\n";


    return 0;
}