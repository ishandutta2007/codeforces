#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=3e5+10;
int r[mn];
int main(){
    string s;
    cin>>s;
    int i,n=s.size(),j;
    memset(r,0x3f,sizeof(r));
    for(i=0;i<n;i++){
        for(j=1;i+j*2<n;j++){
            if(s[i]==s[i+j]&&s[i]==s[i+j*2]){
                r[i]=i+2*j;
                break;
            }
        }
    }
    long long ans=0;
    for(i=n-2;i>=0;i--){
        r[i]=min(r[i],r[i+1]);
        if(r[i]<n)ans+=n-r[i];
    }
    printf("%lld",ans);
}