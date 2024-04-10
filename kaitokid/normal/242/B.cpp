#include <iostream>

using namespace std;

pair<int,int> vc[100005];
int main()
{long up =0,down=1000000008;

long n,x,y;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>x>>y;
    vc[i]=make_pair(x,y);
down=min(x,down);
up=max(y,up) ;
}
for(int i=0;i<n;i++)
{
    if(vc[i].first==down&&vc[i].second==up){cout<<i+1;return 0;}
}
cout<<"-1";
    return 0;
}