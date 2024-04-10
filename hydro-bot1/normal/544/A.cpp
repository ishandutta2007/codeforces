// Hydro submission #6255064017cd4d0a4176479b@1649739330640
#include<bits/stdc++.h>
using namespace std;
string s;int t;
bool a[10000],b[10000];
int main()
{
    int n,i,j;
    cin>>n>>s;
    for(i=0;i<s.size();i++)
    {
        if(!b[s[i]-48])
        a[i]=b[s[i]-48]=true,t++;
        if(t==n)
		{
            printf("YES\n");
            for(j=0;j<s.size();j++)
			{
                printf("%c",s[j]);
                if(a[j+1]) cout<<endl;
            }
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}