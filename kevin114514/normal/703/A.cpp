#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    int Ans=0;
    while(T--)
    {
        int b,p;
        cin>>b>>p;
        if(b>p)
            Ans++;
        if(p>b)
            Ans--;
    }
    if(Ans==0)
        puts("Friendship is magic!^^");
    else if(Ans>0)
        puts("Mishka");
    else    puts("Chris");
    return 0;
}