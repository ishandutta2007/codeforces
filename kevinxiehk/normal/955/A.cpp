#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double hh,mm,h,d,c,n;
    cin>>hh>>mm>>h>>d>>c>>n;
    double tim=hh*60+mm;
    double dis=20*60-tim;
    if(dis<0)dis=0;
    double cosnow=(int)h/(int)(n)+((int)h%(int)(n)!=0);
    cosnow*=c;
    c*=0.8;
    double coslat=(int)(h+dis*d)/(int)(n)+((int)(h+dis*d)%(int)(n)!=0);
    coslat*=c;
    cout<<fixed<<setprecision(10)<<min(cosnow,coslat)<<endl;
    return 0;
}