#include <bits/stdc++.h>
using namespace std;

char ch[long(10e5)+5];
bool maxi[long(10e5)+5];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    cin>>ch;
    long n=strlen(ch),i;
    char maxx;
    maxx=ch[n-1];
    for(i=n-1;i>=0;i--){
        if(ch[i]>=maxx){
            maxi[i]=1;
            maxx=ch[i];
        }
    }
    for(i=0;i<n;i++)if(maxi[i])cout<<ch[i];
    return 0;
}