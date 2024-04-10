/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    string s;
    cin>>s;

    int n=s.size();

    vector<int> odd,even;
    for(int i=0;i<n;i++)
    {
        int x=s[i]-48;
        if(x%2==1) odd.push_back(x);
        else even.push_back(x);
    }

    int i=0,j=0;
    int x=odd.size(),y=even.size();
    while(1)
    {
        if(i==x && j==y) break;

        if(i==x) { cout<<even[j]; j++; continue; }

        if(j==y) { cout<<odd[i]; i++; continue; }

        if(odd[i]<even[j])
        {
            cout<<odd[i];
            i++;
        }
        else
        {
            cout<<even[j];
            j++;
        }
    }
    cout<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}