#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,i,x[3],m=0,f,k,l,ll,kk,m1,m2,j,mm;
    cin>>n;
    map <pair <long,long>,vector <pair <long,long> > > a;
    for(i=0;i<n;++i)
    {
        cin>>x[0]>>x[1]>>x[2];
        sort(x,x+3);
        if(x[0]==x[1])
        {
            if(x[1]==x[2]) a[make_pair(x[2],x[1])].push_back(make_pair(x[0],i));
            else
            {
             a[make_pair(x[2],x[1])].push_back(make_pair(x[0],i));
             a[make_pair(x[1],x[2])].push_back(make_pair(x[0],i));
             a[make_pair(x[0],x[1])].push_back(make_pair(x[2],i));
            }
        }
        else if(x[1]==x[2])
        {
            a[make_pair(x[0],x[1])].push_back(make_pair(x[2],i));
            a[make_pair(x[1],x[0])].push_back(make_pair(x[2],i));
            a[make_pair(x[2],x[1])].push_back(make_pair(x[0],i));
        }
        else
        {a[make_pair(x[2],x[1])].push_back(make_pair(x[0],i));
        a[make_pair(x[1],x[2])].push_back(make_pair(x[0],i));
        a[make_pair(x[0],x[1])].push_back(make_pair(x[2],i));
        a[make_pair(x[1],x[0])].push_back(make_pair(x[2],i));
        a[make_pair(x[2],x[0])].push_back(make_pair(x[1],i));
        a[make_pair(x[0],x[2])].push_back(make_pair(x[1],i));
        }
    }
    map <pair <long,long> ,vector <pair <long,long> > > ::iterator it;
    vector <pair <long,long> > ::iterator iit;
     for(it=a.begin();it!=a.end();++it)
    {
        m1=0,m2=0;k=-1;l=-1;
       for(j=0;j<(it->second).size();++j)
        {
            if((it->second)[j].first>=m1) {m2=m1;m1=(it->second)[j].first;l=k;k=(it->second)[j].second;}
            else if((it->second)[j].first>m2) {m2=(it->second)[j].first;l=(it->second)[j].second;}
        }
        mm=min(min((it->first).first,(it->first).second),m1+m2);
        if(mm>m)
        {
            if(m2>0)
          {
            f=2;ll=l+1;kk=k+1;
          }
            else
          {
            f=1;kk=k+1;ll=-1;
          }
          m=mm;
        }
    }
    if(ll==-1) cout<<'1'<<endl<<kk;
    else cout<<'2'<<endl<<kk<<" "<<ll;
    return 0;
}