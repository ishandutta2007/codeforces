#include <bits/stdc++.h>

using namespace std;
char ch[100];
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    int n,k,br=0,i,v,r,e;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>ch;
        r=strlen(ch);
        e=0;
        for(v=0;v<r;v++){
            if(ch[v]=='4' || ch[v]=='7')e++;
        }
        br++;
        if(e>k)br--;
    }
    cout<<br;
    return 0;
}