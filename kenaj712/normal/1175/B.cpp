#include<bits/stdc++.h>
using namespace std;
vector<long long> v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    long long ans=0,useless=0,act=1,pom,xd=1;
    for(int x=0;x<32;x++)
        xd*=2;
    xd--;
    string co;
    while(t--)
    {
        cin>>co;
        if(co=="add")
        {
            if(useless>0)
            {
                cout<<"OVERFLOW!!!";
                return 0;
            }
            else
                ans+=act;
        }
        else if(co=="for")
        {
            cin>>pom;
            if(act>=1e10)
                useless++;
            else
            {
                act*=pom;
                v.push_back(pom);
            }

        }
        else
        {
            if(useless>0)
                useless--;
            else
            {
                  act/=v.back();
                  v.pop_back();
            }
        }
    }
    if(ans>xd)
        cout<<"OVERFLOW!!!";
    else
        cout<<ans;
	return 0;
}