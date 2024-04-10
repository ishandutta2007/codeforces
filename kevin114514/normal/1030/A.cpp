#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    string Ans="EASY";
    while(N--)
    {
        int X;
        cin>>X;
        if(X)
            Ans="HARD";
    }
    cout<<Ans<<endl;
    return 0;
}