#include <iostream>
#include<algorithm>
#include<vector>
#define X first
#define Y second

using namespace std;

typedef pair<long long,long long> pii;
long long n,m,k,a,t,ans[200000];
vector<int>vec;
vector<pii>v;
bool mark[200000];

int f(int x)
{
    int javab=0;
    while(x>0)
    {
        javab+=ans[x];
        x-=x&(-x);
    }
    return javab;
}

void add(int x)
{
    if(x==0)
    {
        x=1;
        ans[0]++;
    }
    while(x<=n)
    {
        ans[x]++;
        x+=x&(-x);
    }
}

int main()
{
    cin>>n>>k;
    m=n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        t+=a;
        v.push_back(pii(a,i));
    }
    if(t<=k)
    {
        if(t<k)
            cout<<-1<<endl;
        return 0;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        if(m*(v[i].X-1)+v[i].Y+1-f(v[i].Y)>k)
            break;
       // cout<<v[i].X<<"->"<<v[i].Y<<" "<<k<<" "<<m<<" "<<f(v[i].Y)<<endl;
        mark[v[i].Y]=true;
        add(v[i].Y);
        k-=v[i].X;
        m--;
    }
    for(int j=0;j<n;j++)
        if(!mark[j])
            vec.push_back(j);
    for(int i=k%m;i<vec.size();i++)
        cout<<vec[i]+1<<" ";
    for(int i=0;i<k%m;i++)
        cout<<vec[i]+1<<" ";
    cout<<endl;
}