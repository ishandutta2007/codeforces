#include<bits/stdc++.h>
using namespace std;
int main()
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
    for(int i=0;i<N;i++)
    {
        int X;
        cin>>X;
        V[i]-=X;
    }
    sort(V.begin(),V.end());
    long long Ans=0;
    for(int i=0;i<N;i++)
    {
        int pos=lower_bound(V.begin(),V.end(),1-V[i])-V.begin();
        Ans+=N-pos;
    }
    for(int i=0;i<N;i++)
        if(V[i]>0)
            Ans--;
    cout<<Ans/2ll<<endl;
    return 0;
}