#include<bits/stdc++.h>
using namespace std;
long long p,np;
const int mod=998244353;
map<pair<long long,int>,long long> m;
long long rek(long long a,int b)
{
    if(m[make_pair(a,b)]!=0)
        return m[make_pair(a,b)];
    if(a==1)
    {
        if(b==0)
            return p;
        else
            return np;
    }
    if(a%2==1 && b==0)
    {
        m[make_pair(a,b)]=(p*((rek(a/2,0)*(rek(a/2,0))+rek(a/2,1)*rek(a/2,1))%mod)+np*((rek(a/2,1)*(rek(a/2,0))*2)%mod))%mod;
        return m[make_pair(a,b)];
    }
    if(a%2==1 && b==1)
    {
        m[make_pair(a,b)]=(np*((rek(a/2,0)*(rek(a/2,0))+rek(a/2,1)*rek(a/2,1))%mod)+p*((rek(a/2,1)*(rek(a/2,0))*2)%mod))%mod;
        return m[make_pair(a,b)];
    }
    if(a%2==0 && b==0)
    {
        m[make_pair(a,b)]=(rek(a/2,0)*(rek(a/2,0))+rek(a/2,1)*rek(a/2,1))%mod;
        return m[make_pair(a,b)];
    }
    if(a%2==0 && b==1)
    {
        m[make_pair(a,b)]=(rek(a/2,0)*(rek(a/2,1))*2)%mod;
        return m[make_pair(a,b)];
    }

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long a,b,c,d;
    cin>>a>>b>>c>>d;
    p=(d-c+1)/2;
    np=p;
    if((d-c)%2==0)
    {
        if(c%2==1)
            np++;
        else
            p++;
    }
    if(np==0 && (a*b)%2==1)
    {
        cout<<0;
        return 0;
    }
    if((a*b)%2==1)
        cout<<(rek(a*b,1)+rek(a*b,0))%mod;
    else
        cout<<rek(a*b,0);
	return 0;
}