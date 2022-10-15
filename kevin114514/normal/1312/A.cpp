#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int A,B;
        cin>>A>>B;
        if(A%B==0)
        puts("YES");
        else puts("NO");
    }
    return 0;
}