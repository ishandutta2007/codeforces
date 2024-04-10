#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n%2){cout<<-1<<endl;continue;}
        cout<<"0 0 "<<n/2<<endl;
    }
    return 0;
}