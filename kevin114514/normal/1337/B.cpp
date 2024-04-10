#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,A,B;
        cin>>N>>A>>B;
        while(A&&N>20)
        {
            N/=2;
            N+=10;
            A--;
        }
        if(N-B*10<=0)
            puts("YES");
        else    puts("NO");
    }
    return 0;
}