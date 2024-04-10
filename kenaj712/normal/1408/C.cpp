#include<bits/stdc++.h>
using namespace std;
#define double long double
#define int long long
int tab[1000005];
void solve()
{
    int a,b;
    cin>>a>>b;
    for(int x=0;x<a;x++)
        cin>>tab[x];
    int where1=0,where2=a-1;
    double speed1=1,speed2=1;
    double pocz=0,kon=b;
    double ret=0;
    while(where1<=where2)
    {
        double time1=(tab[where1]-pocz)/speed1,time2=(kon-tab[where2])/speed2;
        if(time1<time2)
        {
            where1++;
            pocz+=speed1*time1;
            kon-=speed2*time1;
            speed1++;
            ret+=time1;
        }
        else
        {
            where2--;
            pocz+=speed1*time2;
            kon-=speed2*time2;
            speed2++;
            ret+=time2;
        }
    }
    ret+=(kon-pocz)/(speed1+speed2);
    cout<<ret<<'\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout<<fixed<<setprecision(9);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}