#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,q,t,k,d,i,s[101]={0},an,c;
    cin>>n>>q;
    while(q--)
    {   an=0;c=0;
        cin>>t>>k>>d;
        for(i=1;i<=n;++i)
        {
            if(s[i]<=t) {an+=i;c++;}
            if(c==k) break;
        }
        if(c==k)
        {   c=0;
            for(i=1;i<=n;++i)
            {
                if(s[i]<=t) {s[i]=t+d;c++;}
                if(c==k) break;
            }
            cout<<an;
        }
        else cout<<-1;
        cout<<endl;
    }
    return 0;
}