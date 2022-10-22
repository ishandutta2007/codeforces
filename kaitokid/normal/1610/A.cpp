#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
            int n,m;
            cin>>n>>m;
            if(n==1 && m==1){cout<<0<<endl;continue;}

            if(n==1 || m==1){cout<<1<<endl;continue;}
            cout<<2<<endl;
    }
    return 0;
}