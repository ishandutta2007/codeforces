// Hydro submission #62972adbb0c5e75beb15848e@1654074076153
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,rb,rd,cb,cd,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>m>>rb>>cb>>rd>>cd;
        printf("%d\n",min(rb>rd?2*n-rb-rd:rd-rb,cb>cd?2*m-cb-cd:cd-cb));
    }
    return 0;
}