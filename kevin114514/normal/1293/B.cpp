#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    double ans=0.0;
    for(int i=1;i<=N;i++)
        ans+=1.00/i;
    printf("%.7lf",ans);
    return 0;
}