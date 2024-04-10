#include<bits/stdc++.h>
using namespace std;
map<vector<int> , int> m;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a;
        cin>>a;
        for(int x=0;x<a;x++)
        {
            int c;
            cin>>c;
            int pom = c;
            vector<int> v;
            for(int x=2;x*x<=c;x++)
            {
                int licz = 0;
                while(pom%x == 0)
                {
                    licz++;
                    pom/=x;
                }
                if(licz%2)
                    v.push_back(x);
            }
            if(pom!=1)
                v.push_back(pom);
            m[v]++;
        }
        int maks1 = 0 , maks2 = 0 , licz = 0;
        vector<int> v;
        for(auto x:m)
        {
            //cout<<x.second<<'\n';
            if(x.second%2 == 1)
            {
                maks1 = max(maks1,x.second);
                maks2 = max(maks2,x.second);
            }
            else
            {
                maks1 = max(maks1,x.second);
                licz+=x.second;
            }
            if(x.second%2 == 1 && x.first == v)
                licz += x.second;
        }
        //cout<<'\n';
        m.clear();
         int t;
         cin>>t;
         while(t--)
         {
             long long c;
             cin>>c;
             if(c==0)
                cout<<maks1<<'\n';
             else
                cout<<max(maks2,licz)<<'\n';
         }
    }
	return 0;
}