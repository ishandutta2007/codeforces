#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,last=-1,licz=0,maks=0;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        cin>>b;
        tab[x]=b;
        if(b==last)
            licz++;
        else
        {
            if(last==1)
                v.push_back(licz);
            last=b;
            licz=1;
        }
    }
    if(last==1)
        v.push_back(licz);
    for(auto x:v)
        maks=max(maks,x);
    if(tab[0]==1&&tab[a-1]==1)
        maks=max(v[0]+v.back(),maks);
    cout<<maks;
	return 0;
}