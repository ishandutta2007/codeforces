#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        int a,b;
        cin>>a>>b;
        string s;
        cin>>s;
        vector<int> x;
        int cur=0;
        for(char c:s){
            if(c=='.'){
                ++cur;
            }else if(cur>0){
                x.push_back(cur);
                cur=0;
            }
        }
        if(cur>0){
            x.push_back(cur);
        }
        int cnt[2]={};
        bool ok=false;
        auto f=[&](int x)->int{
            return x>=b&&x<a||x>=2*b;
        };
        auto g=[&](int x)->int{
            return x>=a;
        };
        for(int x:x){
            if(f(x)){
                ++cnt[0];
            }
            if(g(x)){
                ++cnt[1];
            }
        }
        for(int x:x){
            for(int i=0;i+a<=x;++i){
                if(cnt[0]-f(x)+f(i)+f(x-i-a)==0&&(cnt[1]-g(x)+g(i)+g(x-i-a))%2==0){
                    ok=true;
                }
            }
        }
        if(ok){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}