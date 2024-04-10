#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b,c,d=0,pom=1,pom2;
        cin>>a>>b>>c;
        if(c==0)
            cout<<a;
        else if(c==1)
            cout<<b;
        else
        {
            while(a!=0||b!=0)
            {
                pom2=1;
                if(a%2==0&&b%2==0)
                    pom2=0;
                if(a%2==0&&b%2==1&&c%3==0)
                    pom2=0;
                if(a%2==1&&b%2==1&&c%3==2)
                    pom2=0;
                if(a%2==1&&b%2==0&&c%3==1)
                    pom2=0;
                d+=pom*pom2;
                pom*=2;
                a/=2;
                b/=2;
            }
            cout<<d;
        }
        cout<<'\n';
    }
	return 0;
}