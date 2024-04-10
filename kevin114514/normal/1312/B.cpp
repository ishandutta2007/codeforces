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
        vector<int> V;
        for(int i=0;i<N;i++)
        {
            int X;
            cin>>X;
            V.push_back(X);
        }
        sort(V.rbegin(),V.rend());
        for(int i=0;i<N;i++)
            cout<<V[i]<<" ";
        puts("");
    }
    return 0;
}