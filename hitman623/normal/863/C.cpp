#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long alice=0,bob=0;
void play(long a,long b)
{
    if((a==1 && b==3) || (a==3 && b==2) || (a==2 && b==1)) alice++;
    else if((b==1 && a==3) || (b==3 && a==2) || (b==2 && a==1)) bob++;
}
int main()
{
    io
    mll mp,mpa,mpb;
    long k,xx,yy,a[4][4],b[4][4],i,j,t=1,period,scorea,scoreb,aa,bb;
    cin>>k>>xx>>yy;
    for(i=1;i<=3;++i)
    for(j=1;j<=3;++j)
    cin>>a[i][j];
    for(i=1;i<=3;++i)
    for(j=1;j<=3;++j)
    cin>>b[i][j];
    mp[{xx,yy}]=1;
    play(xx,yy);
    mpa[{xx,yy}]=alice;
    mpb[{xx,yy}]=bob;
    k--;
    while(k>0)
    {
        aa=a[xx][yy];
        bb=b[xx][yy];
        if(mp[{aa,bb}]) {period=t-mp[{aa,bb}]+1;play(aa,bb);xx=aa;yy=bb;k--;scorea=alice-mpa[{aa,bb}];scoreb=bob-mpb[{aa,bb}];break;}
        play(aa,bb);
        mp[{aa,bb}]=++t;
        mpa[{aa,bb}]=alice;
        mpb[{aa,bb}]=bob;
        xx=aa;
        yy=bb;
        k--;
    }
    alice+=scorea*(k/period);
    bob+=scoreb*(k/period);
    k%=period;
    while(k>0)
    {
        aa=a[xx][yy];
        bb=b[xx][yy];
        play(aa,bb);
        xx=aa;
        yy=bb;
        k--;
    }
    cout<<alice<<" "<<bob;
    return 0;
}