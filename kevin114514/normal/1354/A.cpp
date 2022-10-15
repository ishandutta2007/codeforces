#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long A,B,C,D;
        cin>>A>>B>>C>>D;
        if(B>=A)
        {
            cout<<B<<endl;
            continue;
        }
        A-=B;
        if(D>=C)
        {
            puts("-1");
            continue;
        }
        D=C-D;
        A=(A+D-1)/D;
        B+=A*C;
        cout<<B<<endl;
    }
    return 0;
}