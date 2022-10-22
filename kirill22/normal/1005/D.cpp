#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll a=0,b=0,ans=0,x=0,si=0;
    bool flag=true;
    string s,s1;
    cin >> s ;
    int m[s.size()+1];
    int m1[s.size()+2];
    m[0]=0;
    m1[s.size()+1]=0;
    m1[0]=0;


    for(ll i=0;i<s.size();++i){
        b+=((char) s[i]);
        b%=3;
        if (b==0){
            ans++;
            x=i+1;

        }
        else{
            for(int u=x;u<i;++u){
                si+=((char) s[u])%3;
                si%=3;
                if (si==b){
                    ans++;
                    x=i+1;
                    si=0;
                    b=0;
                    break;

                }
            }
            si=0;
        }
        m[i+1]=ans;
    }
    b=0;
    x=s.size()-1;
    si=0;
    for(ll i=s.size()-1;i>=0;--i){
        b+=((char) s[i]);
        b%=3;
        if (b==0){
            a++;
            x=i-1;
        }
        else{
            for(int u=x;u<i;++u){
                si+=((char) s[u])%3;
                si%=3;
                if (si==b){
                    a++;
                    x=i-1;
                    si=0;
                    b=0;
                    break;

                }
            }
        }
        m1[i+1]=a;
    }
    ans=0;
    for(int i=0;i<s.size()+1;i++){
        if (m[i]+m1[i+1]>ans){
            ans=m[i]+m1[i+1];
        }
    }
    cout << ans;

}