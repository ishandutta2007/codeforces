#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        if((B-A)%(C+D)==0)
        {
            cout<<(B-A)/(C+D)<<endl;
        }
        else    puts("-1");
    }
    return 0;
}