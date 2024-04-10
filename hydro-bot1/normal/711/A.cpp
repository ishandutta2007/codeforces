// Hydro submission #62550cfa17cd4d0a41764d28@1649741106057
#include<bits/stdc++.h>
using namespace std;
string s[1000];
bool f;
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s[i];
        if(!f&&s[i][0]=='O'&&s[i][1]=='O')
        {
            printf("YES\n");
            s[i][0]='+',s[i][1]='+';
            f=true;
        }
        if(!f&&s[i][3]=='O'&&s[i][4]=='O')
        {
            printf("YES\n");
            s[i][3]='+',s[i][4]='+';
            f=true;
        }
    }
    if(f) for(i=0;i<n;i++)
    cout<<s[i]<<endl;
    else printf("NO\n");
    return 0;
}