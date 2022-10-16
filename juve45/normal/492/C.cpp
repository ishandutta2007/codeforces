#include <iostream>
#include <algorithm>
using namespace std;
long long n, s, lev, i, j, r, essays;
long long avg, sum;
struct chestie
{
    long long nota, b;
}v[100005];
bool comp1(chestie a, chestie b)
{
    if(a.nota<b.nota)
        return 1;
    return 0;
}
bool comp(chestie a, chestie b)
{
    if(a.b<b.b)
        return 1;
    return 0;
}
int main()
{
    cin>>n>>r>>avg;
    avg=avg*n;
    for(i=1;i<=n;i++)
    {
        cin>>v[i].nota>>v[i].b;
        sum+=v[i].nota;
        v[i].nota=r-v[i].nota;
    }
    if(sum>=avg)
    {
        cout<<0;
        return 0;
    }
    sum=avg-sum;
    //cout<<"sum egal "<<sum<<'\n';
    sort(v+1,v+n+1,comp1);
    i=1;
    while(v[i].nota<=0&&i<=n)
        i++;
    sort(v+i,v+n+1,comp);
   // for(int j=i;j<=n;j++)
      //  cout<<v[j].nota<<' '<<v[j].b<<'\n';
    while(i<=n&&sum>0)
    {
        if(v[i].nota<=sum)
            essays+=v[i].b*v[i].nota,sum-=v[i].nota;
        else essays+=sum*v[i].b,sum=0;
        i++;
    }
    cout<<essays;
}