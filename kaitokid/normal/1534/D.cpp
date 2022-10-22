#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int lvl[2009],num[3];
int main()
{       int n;
        cin>>n;
        cout<<"? "<<1<<endl;
        fflush(stdout);
        for(int i=1;i<=n;i++){cin>>lvl[i];num[(lvl[i]%2)]++;}
        vector<pair<int,int> >ans;
        int u;
        if(num[0]<=num[1])u=0;
        else u=1;
        if(u==0)
        {
            for(int i=1;i<=n;i++)if(lvl[i]==1)ans.push_back({1,i});
        }
        for(int i=2;i<=n;i++)
        {
            if((lvl[i]%2)!=u)continue;
            cout<<"? "<<i<<endl;
            fflush(stdout);
            int x;
            for(int j=1;j<=n;j++)
            {
                cin>>x;
                if(x==1)ans.push_back({i,j});
            }

        }
        cout<<"!"<<endl;
        for(int i=0;i<ans.size();i++)
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        fflush(stdout);

    return 0;
}