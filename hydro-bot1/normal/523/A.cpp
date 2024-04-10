// Hydro submission #62550617ac286d0a56b85baf@1649739288056
#include<bits/stdc++.h>
using namespace std;
char c[100][100];
int main()
{
    int w,h,i,j;
    cin>>w>>h;
    for(i=0;i<h;i++)
    for(j=0;j<w;j++)
    cin>>c[j][i];
    for(i=0;i<w;i++)
    {
        for(j=0;j<h;j++)
        printf("%c%c",c[i][j],c[i][j]);
        cout<<endl;
        for(j=0;j<h;j++)
        printf("%c%c",c[i][j],c[i][j]);
        cout<<endl;
    }
    return 0;
}