#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        if(i%2)
            cout<<"I hate ";
        else    cout<<"I love ";
        if(i==N)
            cout<<"it\n";
        else    cout<<"that ";
    }
    return 0;
}