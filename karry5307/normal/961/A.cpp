#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll maxn,cnt,barrel[10001],num,minn=0x7fffffff;
int main()
{
    cin>>maxn>>cnt;
    for(register int i=0;i<cnt;i++)
    {
        cin>>num;
        barrel[num]++;
    }
    for(register int i=1;i<=maxn;i++)
    {
        minn=min(minn,barrel[i]);
    }
    cout<<minn;
}