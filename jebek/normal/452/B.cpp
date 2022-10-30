#include <iostream>
#include<algorithm>
#include<vector>
#define X first
#define Y second
#include<cmath>

using namespace std;

typedef pair<long double,long double> pii;
int n,m;
vector<pii>v;
long double ans=-1;
int ind1,ind2,t;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        if(0+i!=n+m)
            v.push_back(pii(0,i));
    for(int i=0;i<m;i++)
        if(n+i!=0)
            v.push_back(pii(n,i));
    for(int i=1;i<n;i++)
        v.push_back(pii(i,0));
    for(int i=1;i<n;i++)
        v.push_back(pii(i,m));
    for(int i=0;i<v.size();i++)
        for(int j=0;j<v.size();j++)
            if(i!=j)
            {
                long double x=sqrt((v[i].X)*(v[i].X)+(v[i].Y)*(v[i].Y))+sqrt((v[j].X-n)*(v[j].X-n)+(v[j].Y-m)*(v[j].Y-m));
                if(x>=ans)
                {
                    ans=x;
                    ind1=i;
                    ind2=j;
                    t=1;
                }
                x=sqrt((v[i].X)*(v[i].X)+(v[i].Y)*(v[i].Y))+sqrt((v[j].X-v[i].X)*(v[j].X-v[i].X)+(v[j].Y-v[i].Y)*(v[j].Y-v[i].Y));
                if(x>=ans)
                {
                    ans=x;
                    ind1=i;
                    ind2=j;
                    t=2;
                }
                x=sqrt((v[i].X-n)*(v[i].X-n)+(v[i].Y-m)*(v[i].Y-m))+sqrt((v[j].X-v[i].X)*(v[j].X-v[i].X)+(v[j].Y-v[i].Y)*(v[j].Y-v[i].Y));
                if(x>=ans)
                {
                    ans=x;
                    ind1=i;
                    ind2=j;
                    t=3;
                }
            }
    if(t==1)
        cout<<v[ind1].X<<" "<<v[ind1].Y<<endl<<0<<" "<<0<<endl<<n<<" "<<m<<endl<<v[ind2].X<<" "<<v[ind2].Y<<endl;
    if(t==2)
        cout<<n<<" "<<m<<endl<<0<<" "<<0<<endl<<v[ind1].X<<" "<<v[ind1].Y<<endl<<v[ind2].X<<" "<<v[ind2].Y<<endl;
    if(t==3)
        cout<<0<<" "<<0<<endl<<n<<" "<<m<<endl<<v[ind1].X<<" "<<v[ind1].Y<<endl<<v[ind2].X<<" "<<v[ind2].Y<<endl;
}