#include<bits/stdc++.h>
using namespace std;
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
        cout<<"Division ";
        if(n>=1900){cout<<1<<endl;continue;}

        if(n>=1600){cout<<2<<endl;continue;}

        if(n>=1400){cout<<3<<endl;continue;}
        cout<<4<<endl;
    }

    return 0;

}