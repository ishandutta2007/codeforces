#include <iostream>

using namespace std;
int n,m,x,cnt;
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++) {cin>>x;if(x<=5-m)cnt++;}
    cout<<cnt/3;


    return 0;
}