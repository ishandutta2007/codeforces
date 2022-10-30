// Hydro submission #631f2fab32ae6c3198c90ddc@1662988203621
#include<bits/stdc++.h>
using namespace std;
string s[4][1001];
map<string,int> mp;
int main()
{
    int t,n,c,i,j;
    cin>>t;
    while(t--)
    {
        mp.clear();
        cin>>n;
        for(i=1;i<=3;i++)
        for(j=1;j<=n;j++)
        {
            cin>>s[i][j];
            mp[s[i][j]]++;
        }
        for(i=1;i<=3;i++)
        {
            c=0;for(j=1;j<=n;j++)
            switch(mp[s[i][j]])
            {
                case 1:c+=3;break;
                case 2:c++;break;
            }
            printf("%d ",c);
        }
        cout<<endl;
    }
    return 0;
}