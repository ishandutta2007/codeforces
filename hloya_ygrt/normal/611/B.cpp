#include <bits\stdc++.h>

using namespace std;

    const int maxn=2e5;
    const int inf=2e9;
    const int eps=1e-5;

#define pb push_back
#define mp make_pair
#define fir first
#define ll long long
#define sec second
    string a2,b2;
ll getsize(long long n)
{
    ll ans=0;
    while (n)
    {
        n/=2;
        ans++;
    }
    return ans;
}
    bool _less(string a,string b)
    {
        if (a.size()<b.size())
        return 1;
        if (b.size()<a.size())
            return 0;
        for (ll i=0;i<a.size();i++)
        {
            if (a[i]>b[i])
                return 0;
            if (b[i]>a[i])
                return 1;
        }

        return 1;
    }

    string build (long long s)
    {
        string ans;
        long long x=s;
        while (x)
        {
            ans.push_back('1');
            x--;
        }
        return ans;
    }

int main()
{
    long long a,b;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%I64d %I64d",&a,&b);
    long long gans=0;

    ll sa=getsize(a),sb=getsize(b);

    for (ll i=sa+1;i<sb;i++)
        gans+=i-1;

    ll a1=a;
    while (a1)
    {
        a2=(char)(a1%2+48)+a2;
        a1/=2;
    }
      ll b1=b;
    while (b1)
    {
        b2=(char)(b1%2+48)+b2;
        b1/=2;
    }
    //cout<<a2<<endl<<b2<<endl;

    string t1=build(sa),t2=build(sb);

    for (ll i=1;i<t1.size();i++)
    {
        t1[i]='0';
        if (_less(t1,b2)&&_less(a2,t1))
            gans++;
        t1[i]='1';
    }

    if (t1.size()!=t2.size())
      for (ll i=1;i<t2.size();i++)
    {
        t2[i]='0';
        if (_less(t2,b2)&&_less(a2,t2))
            gans++;
        t2[i]='1';
    }

    cout<<gans;
    return 0;
}