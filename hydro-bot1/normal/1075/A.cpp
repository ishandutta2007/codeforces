// Hydro submission #625ceb3ffa9408d417fea90e@1650256704067
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,x,y;
    cin>>n>>x>>y;
    printf(max(x-1,y-1)>max(n-x,n-y)?"Black\n":"White\n");
    return 0;
}