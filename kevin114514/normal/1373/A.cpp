#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int N;
    cin>>N;
    while(N--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        if(C<=A)
            cout<<"-1 ";
        else    cout<<"1 ";
        if(C<A*B)
            cout<<B<<endl;
        else    cout<<-1<<endl;
    }
    return 0;
}