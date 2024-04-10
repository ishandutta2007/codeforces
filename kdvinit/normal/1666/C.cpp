#include<bits/stdc++.h>
using namespace std;
#define int long long




int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    pair<int,int> a[3];
    for(int i=0;i<3;i++)
        {
            cin>>a[i].first>>a[i].second;
        }
    sort(a,a+3);

    vector<int> v;
    for(int i=0;i<3;i++){v.push_back(a[i].second);}
    sort(v.begin(),v.end());
    int my=v[1];
    //if(a[1].second<a[2].second){my=a[1].second;}
    //else{my=a[2].second;}
    cout<<4<<"\n";
    cout<<a[0].first<<" "<<a[0].second<<" "<<a[0].first<<" "<<my<<"\n";
    cout<<a[0].first<<" "<<my<<" "<<a[2].first<<" "<<my<<"\n";
    cout<<a[1].first<<" "<<a[1].second<<" "<<a[1].first<<" "<<my<<"\n";
    cout<<a[2].first<<" "<<a[2].second<<" "<<a[2].first<<" "<<my<<"\n";
}