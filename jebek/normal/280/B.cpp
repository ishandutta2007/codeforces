#include <iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

typedef pair<int,int> pii;
int n,a[100100],MAX;
vector<pii>v;
set<int>s;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        v.push_back(pii(a[i],i));
    }
    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>-1;i--)
    {
        int k=v[i].second;
        set<int>::iterator it=s.upper_bound(k);
        if(it!=s.end())
        {
            MAX=max(MAX,a[k]^(a[*it]));
           // cout<<k<<" "<<*it<<endl;
        }
        if(it!=s.begin())
        {
            it--;
            MAX=max(MAX,a[k]^(a[*it]));
           // cout<<k<<" "<<*it<<endl;
        }
        s.insert(k);
    }
    cout<<MAX<<endl;
}