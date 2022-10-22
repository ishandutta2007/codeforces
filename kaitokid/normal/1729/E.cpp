#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

    for(int i=2;i<27;i++)
    {
        cout<<"? "<<i<<" "<<1<<endl;
        fflush(stdout);
        ll u;
        cin>>u;
        if(u==-1)
        {
            cout<<"! "<<i-1<<endl;
            fflush(stdout);
            return 0;
        }
        cout<<"? "<<1<<" "<<i<<endl;
        fflush(stdout);
        ll v;
        cin>>v;
        if(u!=v)
        {
            cout<<"! "<<u+v<<endl;
            fflush(stdout);
            return 0;
        }
    }



    return 0;
}