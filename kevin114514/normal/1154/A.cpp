#include<bits/stdc++.h>
using namespace std;
int X[4];
int main()
{
    for(int i=0;i<4;i++)
        cin>>X[i];
    sort(X,X+4);
    for(int i=0;i<3;i++)
        cout<<X[3]-X[i]<<" ";
    return 0;
}