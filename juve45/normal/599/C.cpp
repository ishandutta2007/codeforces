#include <bits/stdc++.h>

using namespace std;
#define DMAX 100009
vector <pair <int, int> > v;
int n;
int use[DMAX], h[DMAX], poz, neg, ans;

int main()
{
    v.push_back({0,0});
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>h[i], v.push_back({h[i], i});

    sort(v.begin(), v.end());
    poz=neg=0;
    for(int i=1; i<=n; i++)
    {
        ans++;
        pair<int, int> p;
        p=v[i];
        int j=p.second;
        use[j]++;
        use[i]--;
        if(i!=j)
        poz++,neg++;
        while((poz!=0 || neg!=0))
        {
            i++;
            pair<int, int> p;
            p=v[i];
            int j=p.second;
            if(i!=j)
            {
            if(use[j]<0) neg--;
            else poz++;
            
            if(use[i]>0)poz--;
            else neg++;
            
            use[j]++;
            use[i]--;
            }
            if(i>n)
                break;
        }
    }
    cout<<ans<<'\n';

    return 0;
}