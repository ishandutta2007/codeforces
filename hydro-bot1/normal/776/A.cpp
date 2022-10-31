// Hydro submission #625909aacc64917dc466419e@1650002346897
#include<bits/stdc++.h>
using namespace std;
string s,t,a,b;
int main()
{
    int n,i;
    cin>>s>>t>>n;
    cout<<s<<" "<<t<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        if(s==a) swap(s,b);
        if(s==b) swap(s,a);
        if(t==a) swap(t,b);
        if(t==b) swap(t,a);
        cout<<s<<" "<<t<<endl;
    }
    return 0;
}