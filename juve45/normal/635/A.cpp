#include <iostream>

using namespace std;

int n, k, a, b, l, c,m[33][33];

int nr(int l1, int c1, int l2, int c2)
{
    int r=0;
    for(int i=l1;i<=l2;i++)
        for(int j=c1;j<=c2;j++)
        r+=m[i][j];
return r;
    //return m[l2][c2]+m[l1][c1]-m[l1][c2]-m[l2][c1];
}


int main()
{
cin>>l>>c>>n>>k;
int cnt=0;
for(int i=1;i<=n;i++)
cin>>a>>b, m[a][b]=1;

//for(int i=1;i<=l;i++)
//for(int j=1;j<=c;j++)
  //  m[i][j]+=m[i][j-1]+m[i-1][j]- m[i-1][j-1];

    for(int i1=1;i1<=l;i1++)
    for(int i2=i1;i2<=l;i2++)
        for(int j1=1;j1<=c;j1++)
        for(int j2=j1;j2<=c;j2++)
    {
        if(nr(i1, j1, i2, j2)>=k)
            cnt++;
    }
cout<<cnt<<'\n';
    return 0;
}