#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    cout<<N/2<<endl;
    if(N%2)
    {
        cout<<"3 ";
        N-=3;
    }
    for(int i=0;i<N/2;i++)
        cout<<"2 ";
    return 0;
}