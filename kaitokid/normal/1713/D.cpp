#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans[100009];
bool pw[300009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v;
        for(int i=1;i<=(1<<n);i++)
            v.push_back(i);
        while(v.size()>2)
        {
            vector<int>g;
            for(int i=0;i<v.size();i+=4)
            {
                cout<<"? "<<v[i]<<" "<<v[i+2]<<endl;
                fflush(stdout);
                int x;
                cin>>x;
                if(x==0)
                {
                    cout<<"? "<<v[i+1]<<" "<<v[i+3]<<endl;
                    fflush(stdout);
                    cin>>x;
                    if(x==1)g.push_back(v[i+1]);else g.push_back(v[i+3]);
                    continue;
                }
                if(x==1)
                {
                    cout<<"? "<<v[i]<<" "<<v[i+3]<<endl;
                    fflush(stdout);
                    cin>>x;
                    if(x==1)g.push_back(v[i]);else g.push_back(v[i+3]);
                    continue;


                }
                 cout<<"? "<<v[i+1]<<" "<<v[i+2]<<endl;
                    fflush(stdout);
                    cin>>x;
                    if(x==1)g.push_back(v[i+1]);else g.push_back(v[i+2]);
            }
            v=g;
        }
        if(v.size()==1)
        {
            cout<<"! "<<v[0]<<endl;
            fflush(stdout);
            continue;
        }
        cout<<"? "<<v[0]<<" "<<v[1]<<endl;
        fflush(stdout);
        int x;
        cin>>x;
        if(x==1)cout<<"! "<<v[0]<<endl;else cout<<"! "<<v[1]<<endl;
        fflush(stdout);

    }

    return 0;
}