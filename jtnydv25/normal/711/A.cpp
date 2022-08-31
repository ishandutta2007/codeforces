#include <bits/stdc++.h>
using namespace std;
string B[1005];
int main()
{
    int n;
    string s;
    cin>>n;
    bool found = 0;
    for(int i = 0;i<n;i++)
    {
        cin>>s;
        B[i] = s;
        if(!found)
        {
            if(s[0]=='O'&&s[1]=='O')
            {
                B[i][0] = '+';
                B[i][1] = '+';
                found = 1;    
            }
            if(!found && s[3]=='O' && s[4]=='O')
            {
                B[i][3] = '+';
                B[i][4] = '+';
                found = 1;
            }
        }
    }
    if(!found)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    for(int i = 0;i<n;i++){
        for(int j = 0;j<5;j++)
        {
            cout<< B[i][j];
        }
        cout<<"\n";
    }
    return 0;
}