#include<bits/stdc++.h>
using namespace std;
int main()
{
    string A,B;
    cin>>A>>B;
    for(int i=0;i<A.length();i++)
    {
        if(isupper(A[i]))
            A[i]+=('a'-'A');
        if(isupper(B[i]))
            B[i]+=('a'-'A');
        if(A[i]<B[i])
        {
            puts("-1");
            return 0;
        }
        if(A[i]>B[i])
        {
            puts("1");
            return 0;
        }
    }
    puts("0");
    return 0;
}