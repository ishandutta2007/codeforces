// Hydro submission #631f2df1bdf9bc31d15c7e59@1662987761711
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;pair<int,int> p=minmax(a,b);
        printf((a+b)%3||p.first*2<p.second?"NO\n":"YES\n");
    }
    return 0;
}