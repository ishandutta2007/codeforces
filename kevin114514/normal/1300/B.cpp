#include<bits/stdc++.h>
using namespace std;
int X[1000100];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        N*=2;
        for(int i=0;i<N;i++)
            cin>>X[i];
        sort(X,X+N);
        N/=2;
        cout<<X[N]-X[N-1]<<endl;
    }
    return 0;
}