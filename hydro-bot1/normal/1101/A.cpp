// Hydro submission #625cebf9fa9408d417fea97d@1650256890202
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,l,r,d,i;
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>l>>r>>d;
        printf("%d\n",l>d?d:(r/d+1)*d);
    }
    return 0;
}