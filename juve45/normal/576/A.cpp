#include <bits/stdc++.h>

using namespace std;

vector <int> v, ans;

int prim[1009];

void pre()
{
    prim[0]=1;
    prim[1]=1;

    for(int i=2; i<=1000; i++)
    {
        if(prim[i]==0)
        {
            int j=2*i;
            while(j<=1000)
            {
                prim[j]=1;
                j+=i;
            }
        }
    }
}

int n;


int main()
{

    pre();
    cin>>n;

    for(int i=1; i<=n; i++)
        {
            if(prim[i]==0)
            {
                int j=i;
                while(j<=n)
                {
                    ans.push_back(j);
                    j*=i;
                }
            }
        }

    cout<<ans.size()<<'\n';
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<' ';

    return 0;
}