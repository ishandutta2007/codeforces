#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
const int mn=3e5+10;
string s[100];
int main(){
    int tc;
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>tc;
    while(tc--){
        int r,c;
        cin>>r>>c;
        for(int i=0;i<r;i++)cin>>s[i];
        int ans=5;
        bool hail=1;
        for(int i=0;i<r;i++)for(int j=0;j<c;j++){
            if(s[i][j]=='A'){
                ans=min(ans,4);
                if(i==0||i==r-1||j==0||j==c-1)ans=min(ans,3);
                if((i==0||i==r-1)&&(j==0||j==c-1))ans=min(ans,2);
            }
            else hail=0;
        }
        if(hail)ans=min(ans,0);
        hail=1;
        for(int i=0;i<c;i++)if(s[0][i]!='A')hail=0;
        if(hail)ans=min(ans,1);
        hail=1;
        for(int i=0;i<c;i++)if(s[r-1][i]!='A')hail=0;
        if(hail)ans=min(ans,1);
        hail=1;
        for(int i=0;i<r;i++)if(s[i][0]!='A')hail=0;
        if(hail)ans=min(ans,1);
        hail=1;
        for(int i=0;i<r;i++)if(s[i][c-1]!='A')hail=0;
        if(hail)ans=min(ans,1);
        for(int i=0;i<r;i++){
            hail=1;
            for(int j=0;j<c;j++)if(s[i][j]!='A')hail=0;
            if(hail)ans=min(ans,2);
        }
        for(int i=0;i<c;i++){
            hail=1;
            for(int j=0;j<r;j++)if(s[j][i]!='A')hail=0;
            if(hail)ans=min(ans,2);
        }
        if(ans==5)printf("MORTAL\n");
        else printf("%d\n",ans);
    }
}