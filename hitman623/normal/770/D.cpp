#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    long n,m=0,s,i,j,k,c=0,col=0;
    char a[201],b[500][500];
    cin>>n;
    cin>>a;
    for(i=0;i<n;++i)
    {if(a[i]=='[') c++;
    else c--;
    m=max(m,c);}
    s=2*m+1;
    for(i=0;i<n;++i)
    {
       if(a[i]=='[')
       {
           b[(2*m+1-s)/2][col]='+';
           b[(2*m+1-s)/2][col+1]='-';
           for(j=(2*m+1-s)/2+1;j<s+(2*m+1-s)/2-1;++j)
           b[j][col]='|';
           b[s+(2*m+1-s)/2-1][col]='+';
           b[s+(2*m+1-s)/2-1][col+1]='-';
           s-=2;col++;
       }
       else
       {
           s+=2;
           if(a[i-1]=='[')
           col+=3;
           b[(2*m+1-s)/2][col]='+';
           b[(2*m+1-s)/2][col-1]='-';
           for(j=(2*m+1-s)/2+1;j<s+(2*m+1-s)/2-1;++j)
           b[j][col]='|';
           b[s+(2*m+1-s)/2-1][col]='+';
           b[s+(2*m+1-s)/2-1][col-1]='-';
           col++;
       }
    }
    for(i=0;i<2*m+1;++i)
    {for(j=0;j<col;++j)
    if(b[i][j]=='+' || b[i][j]=='-' || b[i][j]=='|') cout<<b[i][j];
    else cout<<" ";
    cout<<endl;}
    return 0;
}