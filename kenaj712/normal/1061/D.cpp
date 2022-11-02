#include<bits/stdc++.h>
using namespace std;
multiset<int> s;
pair<int,int> tab[1000005];
vector<int> v;
int mod=1e9+7;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b,c,d,e;
    long long zakup=0,suma=0,out=0;
    cin>>a>>b>>c;
    b-=c;
    for(int x=0;x<a;x++)
    {
        cin>>d>>e;
        tab[x]=make_pair(d,e);
        suma+=e-d+1;
    }
    sort(tab,tab+a);
    for(int x=0;x<a;x++)
    {
        int l=tab[x].first,r=tab[x].second,pom;
        /*if(x==4)
        {
            for(multiset<int>::iterator it=s.begin();it!=s.end();it++)
                cout<<*it<<" ";
            break;
        }*/
        if(s.empty()==true)
        {
            s.insert(r);
            zakup++;
        }
        else
        {
            multiset<int>::iterator it=s.lower_bound(l);
            if(it==s.begin())
            {
                zakup++;
                s.insert(r);
            }
            else
            {
                it--;
                pom=(*it);
                v.push_back(l-pom-1);
                s.erase(it);
                s.insert(r);
            }
        }
    }
    for(int x=0;x<v.size();x++)
    {
        if(v[x]*c>=b)
            zakup++;
        else
        {
            out+=(c*v[x]);
            out%=mod;
        }
    }
    zakup%=mod;
    suma%=mod;
    out+=zakup*b;
    out%=mod;
    out+=suma*c;
    out%=mod;
    cout<<out;

	return 0;
}