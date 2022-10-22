#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,int>fr;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;
        int u=-1,sum=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1'){u=i;sum++;}
        }
        if((u==-1)||(sum%2)){cout<<"NO"<<endl;continue;}
        vector<int>g;

        cout<<"YES"<<endl;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')g.push_back((i+1)%n);
        }
        int k=g.size();
        for(int i=0;i<g.size();i++)
        {
            int j=(g[i]+1)%n;
            int h=g[(i+1)%k];
            int d=g[i];
            while(j!=h)
            {
                cout<<d+1<<" "<<j+1<<endl;
                j=(j+1)%n;
                d=(d+1)%n;
            }
        }
        for(int i=1;i<k;i++)
            cout<<g[0]+1<<" "<<g[i]+1<<endl;




    }
    return 0;
}