#include<bits/stdc++.h>
#define LL long long
using namespace std;

char s[300010];
int n,m;

int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    int l=1,r=n,flag=0,ans=0;
    while(l<=r)
    {
//        cout<<l<<" "<<r<<endl;
        if (s[l]!=s[r]) {puts("0");return 0;}
        int L=l,R=r;
        while(l+1<=n&&s[l]==s[l+1]) l++;
        while(r-1>=1&&s[r]==s[r-1]) r--;
//        cout<<l<<" "<<r<<endl;
        if (r<=l)
        {
            if (R-L+1>=2) ans=R-L+2;
            else ans=0;
            break;
        }
        if (l-L+1+R-r+1>=3)
        {
            l++,r--;
        }
        else {puts("0");return 0;}
    }
    printf("%d\n",ans);
    return 0;
}