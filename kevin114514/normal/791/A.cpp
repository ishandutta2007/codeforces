#include<bits/stdc++.h>
using namespace std;
int main()
{
    int A,B;
    cin>>A>>B;
    for(int i=1;;i++)
    {
        A*=3;
        B*=2;
        if(A>B)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}