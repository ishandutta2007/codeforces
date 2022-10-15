#include<bits/stdc++.h>
using namespace std;
int main()
{
    int A,B;
    cin>>A>>B;
    if(B>=A+A)
    {
        puts("Yes");
        for(int i=1;i<A;i++)
        {
            B-=2;
            cout<<2<<" ";
        }
        cout<<B<<endl;
        puts("1");
    }
    else    puts("No");
    return 0;
}