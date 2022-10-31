// Hydro submission #6253b35748f783013279128a@1649652567926
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,l;
    string s;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s;
        l=s.size();
        if(l<11) cout<<s<<endl;
        else printf("%c%d%c\n",s[0],l-2,s[l-1]);
    }
    return 0;
}