#include<bits/stdc++.h>
using namespace std;
int X[100100];
void Solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    for(int i=0;i<a;i++)
        cin>>X[i];
    int Ans=0;
    for(int i=0;i<=c;i++)
    if(i+i+1<=b)
    {
        int Sum=0,mx=0;
        for(int j=0;j<b-i-i+1;j++)
            Sum+=X[j];
        for(int j=1;j<b-i-i+1;j++)
            mx=max(mx,X[j-1]+X[j]);
        Sum+=i*mx;
//      cout<<i<<" "<<Sum<<endl;
        Ans=max(Ans,Sum);
    }
    for(int i=1;i<=c;i++)
    if(i+i<=b)
    {
        int Sum=0,mx=0;
        for(int j=0;j<b-i-i+2;j++)
            Sum+=X[j];
        for(int j=1;j<b-i-i+2;j++)
            mx=max(mx,X[j-1]+X[j]);
        Sum+=(i-1)*mx;
        Sum+=X[b-i-i];
//      cout<<i<<" "<<Sum<<endl;
        Ans=max(Ans,Sum);
    }
    cout<<Ans<<endl;
    return ;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
        Solve();
    return 0;
}