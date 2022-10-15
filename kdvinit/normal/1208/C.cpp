#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin>>n;
    int a[n][n];
    int st=0;
    for(int i=0; i<n; i+=2)
    {
        for(int j=0; j<n; j+=2)
        {
            a[i][j]=st; a[i][j+1]=st+1;
            a[i+1][j]=st+2; a[i+1][j+1]=st+3;
            st+=4;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++) cout<<a[i][j]<<" ";
        cout<<endl;
    }
}