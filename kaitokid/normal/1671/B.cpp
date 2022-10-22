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
        int n,lst;
        cin>>n;
        cin>>lst;
        lst++;
        bool bl=true;
        for(int i=1;i<n;i++)
        {
            int x;
            cin>>x;
            lst++;
            if(x==lst)continue;
            if(x+1==lst)continue;
            if(x-1==lst)continue;
            bl=false;
        }
        if(bl)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;

}