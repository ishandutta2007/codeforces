#include<bits/stdc++.h>
using namespace std;
long long X[100100];
void solve()
{
    int N;
    long long K;
    cin>>N>>K;
    for(int i=0;i<N;i++)
        cin>>X[i];
    sort(X,X+N);
    reverse(X,X+N);
    int cnt=0,last=-1;
    for(int i=0;i<N;i++)
        if(X[i]*(i-last)>=K)
        {
            cnt++;
            last=i;
        }
    cout<<cnt<<endl;
    return ;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}