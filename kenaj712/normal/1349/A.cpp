#include<bits/stdc++.h>
using namespace std;
vector<int> v[2000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        int b;
        cin>>b;
        int pom=b;
        for(int y=2;y*y<=b;y++)
        {
            if(pom%y==0)
            {
                int licz=0;
                while(pom%y==0)
                {
                    licz++;
                    pom/=y;
                }
                v[y].push_back(licz);
            }
        }
        if(pom!=1)
            v[pom].push_back(1);
    }
    long long out=1;
    for(int x=1;x<=2e5;x++)
    {
        if(v[x].size()<a-1)
            continue;
        else
        {
            sort(v[x].begin(),v[x].end());
            reverse(v[x].begin(),v[x].end());
            while(v[x].size()>a-1)
                v[x].pop_back();

            int pom=v[x].back();
            while(pom--)
                out*=x;
        }
    }
    cout<<out;
    return 0;
}