#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
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
        if(n==3)
        {
            cout<<-1<<endl;
            continue;
        }
        if((n%2)==0)
        {
            for(int i=1;i<n;i+=2)cout<<i+1<<" "<<i<<" ";
            cout<<endl;
            continue;
        }
        cout<<"5 4 1 2 3 ";
        for(int i=6;i<n;i+=2)cout<<i+1<<" "<<i<<" ";
        cout<<endl;
    }
    return 0;
}