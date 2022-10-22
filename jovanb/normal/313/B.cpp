#include <bits/stdc++.h>

using namespace std;
char s[100005];
long jed[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    long n,m,a,b,i;
    cin>>s;
    n=strlen(s);
    cin>>m;
    jed[0]=0;
    for(i=1;i<n;i++){
        jed[i]=jed[i-1];
        if(s[i]==s[i-1])jed[i]++;
    }
    for(i=1;i<=m;i++){
        cin>>a>>b;
        cout<<jed[b-1]-jed[a-1]<<endl;
    }
    return 0;
}