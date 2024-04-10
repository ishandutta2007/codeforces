#include<bits/stdc++.h>
using namespace std;
long long a[100100];
int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>a[i];
    if(N==1)
    {
        cout<<1<<" "<<1<<"\n"<<0<<"\n"<<1<<" "<<1<<"\n"<<0<<"\n"<<1<<" "<<1<<"\n"<<(-a[0])<<"\n";
        return 0;
    }
    cout<<1<<" "<<1<<"\n"<<(-a[0])<<endl;
    cout<<2<<" "<<N<<endl;
    for(int i=1;i<N;i++)
    {
        long long MOD=(a[i]%N+N)%N;
        cout<<MOD*(N-1)<<" ";
        a[i]+=MOD*(N-1);
    }
    a[0]=0;
    puts("");
    cout<<1<<" "<<N<<endl;
    for(int i=0;i<N;i++)
        cout<<(-a[i])<<" ";
    return 0;
}