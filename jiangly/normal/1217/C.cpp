#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        int cnt=0;
        int ans=0;
        for(int i=0;i<s.length();++i){
            if(s[i]=='0'){
                ++cnt;
            }else{
                int len=0;
                for(int j=i;j<min((int)s.length(),i+20);++j){
                    len=len*2+s[j]-'0';
                    if(len>=j-i+1&&len<=j-i+1+cnt){
                        ++ans;
                    }
                }
                cnt=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}