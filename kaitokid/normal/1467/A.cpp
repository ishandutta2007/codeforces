#include <bits/stdc++.h>

using namespace std;

int mod=1e9+7;
int main()

{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1){cout<<9<<endl;continue;}

        if(n==2){cout<<98<<endl;continue;}
        cout<<98;
        int u=9;
        n-=2;
        while(n--)
        {
            cout<<u;
            u=(u+1)%10;
        }
        cout<<endl;
    }
      return 0;
}