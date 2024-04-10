#include <iostream>

using namespace std;

int main()
{
    long long n,i=0,j=0,a[500][500],r[500]={0},c[500]={0},d[2]={0},p,q,h=1,f=1,w;
    cin>>n;
    for(i=0;i<n;++i)
    for(j=0;j<n;++j)
        cin>>a[i][j];
    for(i=0;i<n;++i)
        for(j=0;j<n;j++)
    {   if(a[i][j]==0) {p=i;q=j;}
        r[i]+=a[i][j];
        c[i]+=a[j][i];
        if(i==j) d[0]+=a[i][j];
        if(i+j==n-1) d[1]+=a[i][j];
    }
    if(p!=q)
    {h=d[0]-r[p];
    r[p]+=h;
    c[q]+=h;
    if(p+q==n-1) d[1]+=h;}
    else
    {
      h=p!=0?r[0]-d[0]:r[1]-d[0];
      d[0]+=h;
      r[p]+=h;
      c[q]+=h;
      if(p+q==n-1) d[1]+=h;
    }
        if(d[0]==d[1]) w=d[0];
        else {f=0;goto en;}
        for(i=0;i<n;++i)
        {
            if(r[i]!=w) {f=0;break;}
            if(c[i]!=w) {f=0;break;}
        }
        en:
            if(w==0) {h=1;}
            if(h<=0) f=0;
        if(f==1)
         cout<<h;
        else cout<<-1;
    return 0;
}