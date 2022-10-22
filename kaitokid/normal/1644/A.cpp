#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool bl[100];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        char c;
    memset(bl,0,sizeof bl);
    bool ans=true;
    for(int i=0;i<6;i++)
    {
        cin>>c;
        if(c>='a'){bl[c-'a']=true;continue;}
        if(!bl[c-'A'])ans=false;
    }
    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    }
    return 0;
}