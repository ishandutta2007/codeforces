// Hydro submission #62972a29b0c5e75beb1582b5@1654073898108
#include<bits/stdc++.h>
using namespace std;
int p[3];
int main()
{
    int n,l,i,j;
    string s,t;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s>>t;
        sort(s.begin(),s.end());
        for(j=0;j<3;j++)
        {
            p[j]=s.find(char(j+97));
            if(p[j]==-1||t[j]-j-97)
            goto next;
        }
        while(s[p[2]]==99)
        {
            s.insert(p[1],"c");
            s.erase(p[2]+1,1);
            p[2]++;
        }
        next:cout<<s<<endl;
    }
    return 0;
}