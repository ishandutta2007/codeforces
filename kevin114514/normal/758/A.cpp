#include<bits/stdc++.h>
using namespace std;
int X[110];
int main()
{
    int Ans=0;
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>X[i];
    sort(X,X+N);
    reverse(X,X+N);
    for(int i=0;i<N;i++)
        Ans+=X[0]-X[i];
    cout<<Ans<<endl;
    return 0;
}