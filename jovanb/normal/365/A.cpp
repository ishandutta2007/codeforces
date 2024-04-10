#include <bits/stdc++.h>
using namespace std;

char ch[100];
int br[100];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    int n,k,i,j,ans=0;;
    cin>>n>>k   ;
    for(i=0;i<n;i++){
        cin>>ch;
        int v=strlen(ch);
        for(j=0;j<=k;j++)br[j]=0;
        for(j=0;j<v;j++){
            br[ch[j]-'0']++;
        }
        for(j=0;j<=k;j++){
            if(br[j]==0)break;
            if(j==k)ans++;
        }
    }
    cout<<ans;
    return 0;
}