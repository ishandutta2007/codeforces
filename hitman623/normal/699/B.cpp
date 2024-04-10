#include <bits/stdc++.h>

using namespace std;
char a[2002][2002];
int main()
{
    long n,m,i,x=-1,y=-1,xx=-1,yy=-1,c=0,c1=0,c2=0,j;
    cin>>n>>m;
    for(i=0;i<n;++i)
            cin>>a[i];
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
            {
              if(a[i][j]=='*' && x==-1 && y==-1)
              {x=i;y=j;}
              else if(i!=x && j!=y && a[i][j]=='*')
              {
                  xx=i;yy=j;
              }
              if(a[i][j]=='*')c++;
            }
    }
    if(x==-1) x=0,y=0;
    if(xx==-1) {cout<<"YES"<<endl;cout<<x+1<<" "<<y+1;exit(0);}
    for(i=0;i<m;++i)
     if(a[x][i]=='*') c1++;
    for(i=0;i<n;++i)
     if(a[i][yy]=='*') c2++;
     if(a[x][yy]=='*') c1--;
     if(c1+c2==c) {cout<<"YES"<<endl;cout<<x+1<<" "<<yy+1;exit(0);}
     c1=0,c2=0;
    for(i=0;i<m;++i)
     if(a[xx][i]=='*') c1++;
    for(i=0;i<n;++i)
     if(a[i][y]=='*') c2++;
     if(a[xx][y]=='*') c1--;
     if(c1+c2>=c) {cout<<"YES"<<endl;cout<<xx+1<<" "<<y+1;exit(0);}
     cout<<"NO";
    return 0;
}