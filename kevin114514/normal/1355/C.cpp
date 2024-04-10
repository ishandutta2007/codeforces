#include<bits/stdc++.h>
using namespace std;
long long Can[1001000],Pre[1001000];
int main()
{
    int A,B,C,D;
    cin>>A>>B>>C>>D;
    for(int i=0;i<=D-C;i++)
        Can[C+i]=i+1;
    for(int i=D;i<1001000;i++)
    	Can[i]=D-C+1;
    Pre[0]=Can[0];
    for(int i=1;i<1001000;i++)
        Pre[i]=Pre[i-1]+Can[i];
    long long Ans=0;
    for(int i=A;i<=B;i++)
        Ans+=Pre[i+C-1]-Pre[i+B-2];
    cout<<Ans<<endl;
    return 0;
}