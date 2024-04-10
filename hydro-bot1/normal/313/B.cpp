// Hydro submission #62ef20bf74879b352565d899@1659838656100
#include<bits/stdc++.h>
using namespace std;
int t[100001];
int main()
{
	string s;cin>>s;
	int n=s.size(),m,l,r,i;
    cin>>m;s=' '+s;
    for(i=1;i<n;i++)
    t[i+1]=t[i]+(s[i]==s[i+1]);
    for(i=1;i<=m;i++)
	{
        cin>>l>>r;
        printf("%d\n",t[r]-t[l]);
    }
    return 0;
}