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
        if(N<=30)
        {
            puts("NO");
            continue;
        }
        puts("YES");
        if(N==36)
        {
            puts("5 6 10 15");
            continue;
        }
        if(N==40)
        {
            puts("3 6 10 21");
            continue;
        }
        if(N==44)
        {
            puts("6 7 10 21");
            continue;
        }
        cout<<6<<" "<<10<<" "<<14<<" "<<N-30<<endl;
    }
    return 0;
}