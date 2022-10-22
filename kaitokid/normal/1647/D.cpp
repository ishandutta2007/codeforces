#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool prime(int x)
{   int r=sqrt(x);
    for(int i=2;i<=r;i++)
        if(x%i==0)return false;
    return true;
}
bool pr[100009];
map<int,int>g;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(ll i=2;i<=100000;i++)
    {
        if(pr[i])continue;
        ll s=i*i;
        while(s<=1000000000){g[s]=i;s*=i;}
        for(ll j=2*i;j<=100000;j+=i)pr[j]=true;
    }
    int t;
    cin>>t;
    while(t--)
    {
        ll x,d;
        cin>>x>>d;
        ll  f=x;
        if(x%(d*d)!=0){cout<<"NO"<<endl;continue;}
        if(prime(d))
        {
            while(x%d==0)x/=d;
            if(x==1||prime(x)){cout<<"NO"<<endl;continue;}
            cout<<"YES"<<endl;
            continue;
        }
        if(g[d]!=0)
        {
            ll u=g[d];
            int h=0;
            while(x%d==0){x/=d;h++;}
           // if(x==1||prime(x)){cout<<"NO"<<endl;continue;}
            if(!prime(x)&&(x!=1)){cout<<"YES"<<endl;continue;}

            if(x==u && d==(u*u))
            {
            if(h>=4) {cout<<"YES"<<endl;continue;}
            }
            else
            {
             if(h>=3) {cout<<"YES"<<endl;continue;}

            }
            cout<<"NO"<<endl;
            continue;
        }
        /*if(g[d]!=0)
        {
            ll u=g[d],s=0,v=0;
            while(x%u==0){s++;x/=u;}
            while(d%u==0){v++;d/=u;}
            if(!prime(x)){cout<<"YES"<<endl;continue;}
            if(v==2)
            {
                if(s>=8||s==6){cout<<"YES"<<endl;continue;}
                cout<<"NO"<<endl;continue;

            }
            if(s>=4*v){cout<<"YES"<<endl;continue;}
            if(s>=3*v+2){cout<<"YES"<<endl;continue;}
            if(s==3*v){cout<<"YES"<<endl;continue;}
            if()

        }
        */
        if((x%(d*d*d))==0){cout<<"YES"<<endl;continue;}
        x/=(d*d);
        if(x==1||prime(x)){cout<<"NO"<<endl;continue;}
        cout<<"YES"<<endl;

    }
    return 0;
}