#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[100][100],ans[100][100];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin>>s[i][j];
            if(s[i][j]=='o')ans[i][j]='o';
            else ans[i][j]='.';
        }

        for(int i=0;i<m;i++)
        {
            int j=0;
            while(j<n)
            {
                if(s[j][i]=='o'){j++;continue;}
                int r=0;
                while(j<n && s[j][i]!='o'){if(s[j][i]=='*')r++; j++;}
                for(int q=j-r;q<j;q++)ans[q][i]='*';


            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)cout<<ans[i][j];
            cout<<endl;
        }


    }

    return 0;

}