#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
void solve(){
    string s;
    cin>>s;
    int cnt[15];
    for(int i=0;i<=9;i++){
        cnt[i]=0;
    }
    int len=s.length();
    for(int i=0;i<len;i++){
        cnt[s[i]-'0']++;
    }
    int ans=len;
    for(int i=0;i<=9;i++){
        ans=min(ans,len-cnt[i]);
    }
    for(char c='0';c<='9';c++){
        for(char cc='0';cc<='9';cc++){
            if(c==cc)continue;
            bool l=true;
            int tcnt=0;
            for(int i=0;i<len;i++){
                if(l){
                    if(s[i]!=c)tcnt++;
                    else l=false;
                }
                else{
                    if(s[i]!=cc)tcnt++;
                    else l=true;
                }
            }
            if(!l)tcnt++;
            ans=min(ans,tcnt);
        }
    }
    cout<<ans<<endl;
    return ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}