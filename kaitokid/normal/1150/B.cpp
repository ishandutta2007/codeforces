#include <iostream>

using namespace std;
char ch[66][66];
int n;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        cin>>ch[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
    {
        if(ch[i][j]=='#')continue;
        if(i>n-3||j==0||j==n-1){cout<<"NO";return 0;}
        for(int q=j-1;q<j+2;q++){if(ch[i+1][q]=='#'){cout<<"NO";return 0;} ch[i+1][q]='#';}
    if(ch[i+2][j]=='#'){cout<<"NO";return 0;}
    ch[i+2][j]='#';
    }
    cout<<"YES";

    return 0;
}