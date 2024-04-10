#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
        {
            char c1;
            cin>>c1;
            if(c1 != 'B'&&c1 != 'W'&&c1!='G'){
                cout<<"#Color";
                return 0;
            }
        }
    cout<<"#Black&White";
}