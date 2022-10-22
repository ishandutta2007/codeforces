#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
int a[200010];

map< pair<int,int> , int > mp;
map< pair<int,int> , int >::iterator it;

int main()
{
    int n,x,g;
    int maxx = 0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int add = 0;
    int k2 = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(a[i] == 0)
        {
            if(x==0)
            {
                add++;
            }
            continue;
        }
        else{
            bool fu = false;
            if(x==0)
            {
                //k2++;
                mp[make_pair(0,0)]++;
                continue;
            }
            long long t1 = x,t2 = a[i];
            if(t1*t2<0)
            {
                fu = true;
            }
            a[i] = abs(a[i]);
            x=abs(x);
            g = __gcd( a[i] , x );
            //cout<<g<<endl;
            if(fu)
            {
                x = -x;
            }
            mp[ make_pair(x/g,a[i]/g)]++;
        }
    }

    for(it = mp.begin();it != mp.end() ;it++)
    {
        if( it->second > maxx )
        {
            maxx = it->second;
        }
    }
   // maxx = max(maxx,k2);
    cout<<maxx+add<<endl;
    return 0;
}