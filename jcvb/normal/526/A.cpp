#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
#define mo 1000000007
typedef long long ll;
int qp(int a,int b){
    int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);
    return ans;
}



int n;
char s[111];
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    for (int i=1;i<=n;i++)
        for (int d=1;i+4*d<=n;d++)
            if(s[i]=='*' && s[i]==s[i+d] && s[i+d]==s[i+d+d] && s[i+d+d]==s[i+d+d+d] && s[i+d+d+d]==s[i+4*d]){
                printf("yes\n");
                return 0;
            }
    printf("no\n");
    return 0;
}