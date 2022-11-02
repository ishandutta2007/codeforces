#include<bits/stdc++.h>
using namespace std;
vector<long long> v;
long long A,B;
int check(int a,int b)
{
    return (upper_bound(v.begin(),v.end(),b)-v.begin())-(lower_bound(v.begin(),v.end(),a)-v.begin());
}
long long rek(long long l,long long r)
{
    if(l==r)
    {
        if(check(l,r)==0)
            return A;
        else
            return B*check(l,r);
    }
    if(check(l,(l+r)/2)==0&&check((l+r)/2+1,r)==0)
        return A;
    if(check(l,(l+r)/2)!=0&&check((l+r)/2+1,r)!=0)
        return rek(l,(l+r)/2)+rek((l+r)/2+1,r);
    else
    {
        long long pom,pom1;
        if(check(l,(l+r)/2)!=0)
        {
            pom=rek(l,(l+r)/2);
            pom1=check(l,(l+r)/2);
        }
        else
        {
            pom=rek((l+r)/2+1,r);
            pom1=check((l+r)/2+1,r);
        }
        return min(pom+A,B*pom1*(r-l+1));
    }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long a,b,e;
	cin>>a>>b>>A>>B;
	while(b--)
    {
        cin>>e;
        v.push_back(e);
    }
	sort(v.begin(),v.end());
    int pot=1;
    while(a--)
        pot*=2;
    cout<<rek(1,pot);
	return 0;
}