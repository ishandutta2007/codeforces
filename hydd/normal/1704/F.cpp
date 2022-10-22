#include<bits/stdc++.h>
using namespace std;
int T,n,sg[510000];
string s; bool vis[510000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sg[0]=0; sg[1]=0;
//	https://oeis.org/A002187
    for (int i=2;i<=100;i++){
        for (int j=0;j<=i-2;j++)
            vis[sg[j]^sg[i-2-j]]=true;
        while (vis[sg[i]]) sg[i]++;
        for (int j=0;j<=i-2;j++)
            vis[sg[j]^sg[i-2-j]]=false;
//        cerr<<sg[i]<<' ';
    }
    for (int i=101;i<=500000;i++) sg[i]=sg[i-34];

    cin>>T;
    while (T--){
        cin>>n>>s; int R=0,B=0;
        for (int i=0;i<n;i++)
            if (s[i]=='R') R++;
            else B++;
        if (R>B) cout<<"Alice\n";
        else if (R<B) cout<<"Bob\n";
        else{
            int ans=0;
            for (int i=0;i<n;){
                int j=i+1;
                while (j<n&&s[j]!=s[j-1]) j++;
                ans^=sg[j-i]; i=j;
            }
            if (ans) cout<<"Alice\n";
            else cout<<"Bob\n";
        }
    }
    return 0;
}