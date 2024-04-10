// Hydro submission #62590d38cc64917dc4664510@1650003256688
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,t=0,mx=0,l;
    string s;cin>>l;
    while(cin>>s)
    {
    	for(i=0;i<s.size();i++)
    	if(s[i]>64&&s[i]<91) t++;
    	mx=max(mx,t),t=0;
    }
    printf("%d\n",mx);
    return 0;
}