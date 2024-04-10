// Hydro submission #628508868adeacb301bcbac3@1652885639405
#include<cstdio>
    #include<cstring>
    #include<iostream>
    #include<algorithm>
    using namespace std;
    typedef long long ll;
    void gcd(ll a,ll b,ll &d,ll &x,ll &y)
    {
        if(!b)
        {
            x=1;
            y=0;
            d=a;
        }
        else
        {
            gcd(b,a%b,d,y,x);
            y-=x*(a/b);
        }
    }
    int main()
    {
        ll a,b,c,x,y,d;
        while(cin>>a>>b>>c)
        {
            gcd(a,b,d,x,y);
            if(c%d!=0)
                puts("-1");
            else
                cout<<-x*(c/d)<<' '<<-y*(c/d)<<endl;
        }

        return 0;
    }