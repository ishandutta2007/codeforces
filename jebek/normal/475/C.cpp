#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

const long long INF=1000000000;
long long MIN,ans;
int n,m;
char c[2000][2000];
vector<int>v[2000],vec;

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>c[i][j];
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(c[i][j]=='X')
            {
                if(v[j].size()==0)
                    v[j].push_back(i);
                else if(v[j].size()==2)
                {
                    cout<<-1<<endl;
                    return 0;
                }
            }
            else if(v[j].size()==1)
                v[j].push_back(i);
        }
        if(v[j].size()==1)
            v[j].push_back(n);
   //     cout<<j<<endl;
        if((v[j].size()==2 && vec.size()==2) || (vec.size()>0 && v[j].size()>0 && (v[j-1][0]>v[j][0] || v[j-1][1]>v[j][1])))
        {
            cout<<-1<<endl;
            return 0;
        }
        if(vec.size()==0 && v[j].size()==2)
            vec.push_back(j);
        if(vec.size()==1 && v[j].size()==0)
            vec.push_back(j);
    }
    if(vec.size()==0)
    {
        cout<<0<<endl;
        return 0;
    }
    if(vec.size()==1)
    {
        vec.push_back(m);
    }
    int a=vec[0],b=vec[1];
    MIN=INF;
    for(int i=vec[0];i<vec[1];i++)
    {
      //  cout<<a<<" "<<b<<" "<<i<<endl;
        if(v[a][0]!=v[i][0] || v[b-1][1]!=v[b+a-i-1][1])
            break;
        if(i==vec[1]-1)
            ans=1;
        else
            ans=v[a][1]-v[i+1][0];
      //  cout<<i<<" "<<ans<<" "<<v[1][1]<<" "<<v[3][0]<<endl;
        for(int j=i+2;j<b;j++)
            if(ans!=v[a+j-i-1][1]-v[j][0])
                ans=INF;
        //cout<<i<<" "<<ans<<endl;
        if(ans>0)
            MIN=min(MIN,ans*(i-a+1));
    }
    if(MIN>=INF)
        cout<<-1<<endl;
    else
        cout<<MIN<<endl;
}