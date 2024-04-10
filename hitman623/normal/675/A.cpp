#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a,b,c;
    cin>>a>>b>>c;
    if(c==0)
    {
        if(b==a) cout<<"YES";
        else cout<<"NO";
        exit(0);
    }
    if((b-a)%abs(c)==0 && (b-a)*c>=0) cout<<"YES";
    else cout<<"NO";
    return 0;
}