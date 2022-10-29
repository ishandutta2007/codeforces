#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int main()
{
    long n,m,k,j,i,f,x;
    cin>>n>>m;
    map < long ,long > mp;
    for(i=0;i<m;++i)
    {
        cin>>k;
        f=1;
        mp.clear();
        for(j=0;j<k;++j)
        {
            cin>>x;
            mp[x]++;
            if(mp[x]>0 && mp[-x]>0) f=0;
        }
        if(f==1) {cout<<"YES";exit(0);}
    }
    cout<<"NO";
    return 0;
}