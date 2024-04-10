#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define pb push_back

using namespace std;

vector <pair<int, int> > v;

int n, a, ans[120], c, k;

int main()
{
cin>>n>>k;


    for(int i=1;i<=n;i++)
        cin>>a, v.pb({a, i});

    sort(v.begin(), v.end(), greater<pair<int, int> >());

    while(k>=0 && !v.empty())
    {
        if(k-v[v.size()-1].first>=0)
        ans[c]=v[v.size()-1].second, c++;

        k=k-v[v.size()-1].first;
        v.pop_back();

    }
    cout<<c<<'\n';
    for(int i=0;i<c;i++)
        cout<<ans[i]<<" \n"[i==c-1];

    return 0;
}