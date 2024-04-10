#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,M;
    cin>>N>>M;
    N*=M;
    M=0;
    while(N--)
    {
        int A,B;
        cin>>A>>B;
        if(A||B)
            M++;
    }
    cout<<M<<endl;
    return 0;
}