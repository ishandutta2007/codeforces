#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{

    ios::sync_with_stdio(0);
    int t,l,r;
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        if(2*l>r){cout<<-1<<" "<<-1<<endl;continue;}
        cout<<l<<" "<<2*l<<endl;
    }
    return 0;
}