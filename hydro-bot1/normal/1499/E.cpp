// Hydro submission #617a347791e11cbec94f360f@1635398776596
#include<bits/stdc++.h>
using namespace std;
const int N=1005,mod=998244353;
string s,t;
int f[N][N][2][4],ans;
void add(int &x,int y){x=(x+y)%mod;}
int main(){
    std::ios::sync_with_stdio(false);
    cin>>s>>t;
    s=' '+s,t=' '+t;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<t.size();j++){
            if(i<s.size()-1)add(f[i+1][j][0][1],1);
            if(j<t.size()-1)add(f[i][j+1][1][2],1);
            for(int k=0;k<4;k++){
                if(i<s.size()-1&&s[i]!=s[i+1])add(f[i+1][j][0][k|1],f[i][j][0][k]);
                if(j<t.size()-1&&s[i]!=t[j+1])add(f[i][j+1][1][k|2],f[i][j][0][k]);
                if(i<s.size()-1&&t[j]!=s[i+1])add(f[i+1][j][0][k|1],f[i][j][1][k]);
                if(j<t.size()-1&&t[j]!=t[j+1])add(f[i][j+1][1][k|2],f[i][j][1][k]);
            }
        }
    }
    for(int i=0;i<s.size();i++)for(int j=0;j<t.size();j++){
        add(ans,f[i][j][0][3]);
        add(ans,f[i][j][1][3]);
    }
    cout<<ans;
}