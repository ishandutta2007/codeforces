#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        bool o=false,e=false;
        for(int i=0;i<N;i++)
        {
            int X;
            cin>>X;
            if(X%2)
                o=true;
            else    e=true;
        }
        if(o&&e)
            puts("YES");
        else if(o)
        {
            if(N%2)
                puts("YES");
            else    puts("NO");
        }
        else    puts("NO");
    }
    return 0;
}