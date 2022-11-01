#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int,int> pii;
long long n,x,t,h,m,MAX,ans1,ans2,ind1,ind2,x1,f=2100;
vector<long long>v[4000][3],v1[4000][3];

bool check1()
{
    MAX=0;
    for(int i=1;i<=min(x,f);i++)
        for(int j=0;j<v[i][0].size();j++)
        {
            if(v[i][0][j]>MAX)
            {
                MAX=v[i][0][j];
                ind1=i;
                ind2=j;
            }
        }
    if(MAX==0)
        return false;
    x+=MAX;
    for(int i=ind2;i<v[ind1][0].size()-1;i++)
        v[ind1][0][i]=v[ind1][0][i+1];
    v[ind1][0].pop_back();
    return true;
}

bool check2()
{
    MAX=0;
    for(int i=1;i<=min(x,f);i++)
        for(int j=0;j<v[i][1].size();j++)
        {
            if(v[i][1][j]>MAX)
            {
                MAX=v[i][1][j];
                ind1=i;
                ind2=j;
            }
        }
    if(MAX==0)
        return false;
    x+=MAX;
    for(int i=ind2;i<v[ind1][1].size()-1;i++)
        v[ind1][1][i]=v[ind1][1][i+1];
    v[ind1][1].pop_back();
    return true;
}


int main()
{
    cin>>n>>x;
    x1=x;
    for(int i=1;i<=n;i++)
    {
        cin>>t>>h>>m;
        v[h][t].push_back(m);
        v1[h][t].push_back(m);
    }
    while(ans1<n)
    {
        if(check1())
            ans1++;
        else
            break;
        if(check2())
            ans1++;
        else
            break;
    }
    for(int i=1;i<=2000;i++)
    {
        v[i][0]=v1[i][0];
        v[i][1]=v1[i][1];
    }
    x=x1;
    while(ans2<n)
    {
        if(check2())
            ans2++;
        else
            break;
        if(check1())
            ans2++;
        else
            break;
    }
    cout<<max(ans2,ans1)<<endl;
}