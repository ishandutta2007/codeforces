#include<bits/stdc++.h>
using namespace std;
int pref[1000005];
string a;
int f(int c,int d)
{
    int pom=0,pot=1;
    for(int x=d;x>=c;x--)
    {
        if(a[x]=='1')
            pom+=pot;
        pot*=2;
    }
    return pom;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a;
        long long ans=0;
        for(int x=1;x<a.size();x++)
            if(a[x-1]=='0')
                pref[x]=pref[x-1]+1;
        for(int x=0;x<20;x++)
            for(int y=0;y+x<a.size();y++)
            {
                int pom=f(y,y+x);
                if(pom<=x+1+pref[y]&&x+1<=pom&&a[y]=='1')
                    ans++;
            }
        cout<<ans<<'\n';
        for(int x=0;x<=a.size();x++)
            pref[x]=0;
    }
	return 0;
}