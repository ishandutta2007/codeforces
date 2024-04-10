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
        int S=N-1;
        for(int i=0;i<N;i++)
        {
            int x;
            cin>>x;
            S+=x;
        }
        cout<<S/N<<endl;
    }
    return 0;;
}