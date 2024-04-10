#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int win[55][55];
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
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)win[i][j]=0;
    string s;
    cin>>s;
    vector<int>v;
    for(int i=0;i<n;i++)
        if(s[i]=='2')v.push_back(i);
        int r=v.size();
        if(r>=1 && r<3){cout<<"NO"<<endl;continue;}
        for(int i=0;i<v.size();i++)
        {
            int u=v[i],d=v[(i+1)%r];
            win[u][d]=1;
            win[d][u]=-1;
        }
        cout<<"YES"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j){cout<<"X";continue;}
            if(win[i][j]==1){cout<<"+";continue;}
            if(win[i][j]==-1){cout<<"-";continue;}
            cout<<"=";
        }
        cout<<endl;
    }

}

    return 0;
}