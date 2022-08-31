#include<bits/stdc++.h>
using namespace std;
class Solver{
private:
    int T;
    string s,t,p;
    int need[26],have[26];
public:
    void solve(){
        cin>>T;
        while(T--){
            cin>>s>>t>>p;
            int len=0;
            for(int i=0;i<t.length()&&len<s.length();++i){
                if(t[i]==s[len]){
                    ++len;
                }
            }
            if(len<s.length()){
                cout<<"NO"<<endl;
            }else{
                memset(need,0,sizeof(need));
                memset(have,0,sizeof(have));
                for(char c:s){
                    --need[c-'a'];
                }
                for(char c:t){
                    ++need[c-'a'];
                }
                for(char c:p){
                    ++have[c-'a'];
                }
                bool ok=true;
                for(int i=0;i<26;++i){
                    if(need[i]>have[i]){
                        ok=false;
                    }
                }
                if(ok){
                    cout<<"YES"<<endl;
                }else{
                    cout<<"NO"<<endl;
                }
            }
        }
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solver().solve();
    return 0;
}