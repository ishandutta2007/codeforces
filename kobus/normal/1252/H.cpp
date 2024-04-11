#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define MOD 1000000007
#define int long long
#define pii pair<int,int>
#define pdd pair<long double,long double>
#define ld long double
#define f first
#define s second
#define eps 1e-8


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    srand(time(NULL));
    cout.precision(11);
    cout.setf(ios::fixed);

    int a,b,m;
    ld vx,vy,vz;

    cin>>a>>b>>m>>vx>>vy>>vz;

    vy=abs(vy);

    ld time = m/vy;

    pdd ini={(1.*a)/2,0};
    ini.f+=vx*time;
    ini.s+=vz*time;

    int quadx;
    if(ini.f>-eps)quadx=ini.f/a;
    else quadx=ini.f/a-1;
    
    int quadz;
    if(ini.s>-eps)quadz=ini.s/b;
    else quadz=ini.s/b-1;

    ini.f-=quadx*a;
    ini.s-=quadz*b;

    if(quadx%2)ini.f=a-ini.f;
    if(quadz%2)ini.s=b-ini.s;

    cout<<ini.f<<" "<<ini.s<<endl;

}