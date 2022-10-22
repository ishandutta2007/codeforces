#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;
        int u=0;
        for(int i=0;i<n;i++)if(s[i]=='0')u++;
        if(u==0){cout<<"DRAW\n";continue;}
        if(u==1){cout<<"BOB\n";continue;}
        if((u%2)==0){cout<<"BOB\n";continue;}
        cout<<"ALICE\n";
    }
}