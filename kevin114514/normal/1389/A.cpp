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
        if(A+A<=B)
        {
            cout<<A<<" "<<A+A<<endl;
        }
        else    puts("-1 -1");
    }
    return 0;
}