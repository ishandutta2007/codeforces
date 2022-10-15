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
        sort(V.begin(),V.end());
        vector<int> V1;
        for(int i=0;i<N;i++)
        {
            V1.push_back(V[i]);
            V1.push_back(V[N-i-1]);
        }
        V1.resize(N);
        reverse(V1.begin(),V1.end());
        for(int i=0;i<N;i++)
            cout<<V1[i]<<" ";
        puts("");
    }
    return 0;
}