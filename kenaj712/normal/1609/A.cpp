#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int a;
    cin>>a;
    vector<long long > v;
    int licz = 0;
    for(int x=0;x<a;x++)
    {
        int b;
        cin>>b;
        while(b%2==0)
        {
            licz++;
            b/=2;
        }
        v.push_back(b);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    while(licz--)
        v[0] *= 2;
    long long sum = 0;
    for(auto x:v)
        sum += x;
    cout<<sum<<'\n';

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}