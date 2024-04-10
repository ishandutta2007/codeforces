#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b)
        return gcd(b,a%b);
    return a;
}
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        string a,b;
        cin>>a>>b;
        int la=a.length(),lb=b.length();
        int lcm=la*lb/gcd(la,lb);
        la=lcm/la;
        lb=lcm/lb;
        string s,t;
        for(int i=0;i<la;i++)
            s+=a;
        for(int i=0;i<lb;i++)
            t+=b;
        if(s==t)
            cout<<s<<endl;
        else    puts("-1");
    }
    return 0;
}