#include <iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

const long long MAXN=300;
long long sum[1000][10];
vector<long long>vec,v[1000];
long long n,ind;

void ok(long long x)
{
    for(long long i=0;i<5;i++)
        sum[x][i]=0;
    for(long long i=0;i<v[x].size();i++)
        sum[x][i%5]+=v[x][i];
}

void relax()
{
    vec.clear();
    for(long long i=0;i<ind;i++)
    {
        for(long long j=0;j<v[i].size();j++)
            vec.push_back(v[i][j]);
        v[i].clear();
    }
    ind=0;
    for(long long i=0;i<vec.size();i++)
    {
        v[ind].push_back(vec[i]);
        if(v[ind].size()>=MAXN)
            ind++;
    }
    ind++;
    for(long long i=0;i<ind;i++)
        ok(i);
}

int main()
{
    cin>>n;
    ind=1;
    for(long long q=0;q<n;q++)
    {
        string s;
        cin>>s;
        long long x;
        if(s=="add")
        {
            cin>>x;
            long long i=0;
            while(i<ind-1 && v[i].back()<x)
                i++;
            v[i].push_back(x);
            long long j=v[i].size()-1;
            while(j>0 && v[i][j]<v[i][j-1])
            {
                swap(v[i][j],v[i][j-1]);
                j--;
            }
            if(v[i].size()>=2*MAXN)
                relax();
            else
                ok(i);
        }
        else if(s=="del")
        {
            cin>>x;
            long long i=0;
            while(v[i].back()<x)
                i++;
            for(long long j=0;j<v[i].size()-1;j++)
                if(v[i][j]>=x)
                    v[i][j]=v[i][j+1];
            v[i].pop_back();
            if(v[i].size()==0 && i<ind-1)
                relax();
            else
                ok(i);
        }
        else
        {
            long long ans=0,t=2;
            for(long long i=0;i<ind;i++)
            {
                ans+=sum[i][t];
                t=(t-(v[i].size()%5)+5)%5;
            }
            cout<<ans<<endl;
        }
    }
}