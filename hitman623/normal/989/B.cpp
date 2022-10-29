#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,p,f;
string s;
void solve(){
    cin>>n>>p>>s;
    rep(i,0,n-p){
        if(s[i]=='.' and s[i+p]=='.'){
            s[i]='1';
            s[i+p]='0';
            rep(j,0,n){
                if(s[j]=='.'){
                    cout<<'0';
                }
                else cout<<s[j];
            }
            return;
        }
        else if(s[i]=='.'){
            s[i]='0'+'1'-s[i+p];
            rep(j,0,n){
                if(s[j]=='.'){
                    cout<<'0';
                }
                else cout<<s[j];
            }
            return;            
        }
        else if(s[i+p]=='.'){
            s[i+p]='0'+'1'-s[i];
            rep(j,0,n){
                if(s[j]=='.'){
                    cout<<'0';
                }
                else cout<<s[j];
            }
            return;                        
        }
        else if(s[i]!=s[i+p]){
            f=1;
        }
    }
    if(f){
        rep(j,0,n){
            if(s[j]=='.'){
                cout<<'0';
            }
            else cout<<s[j];
        }
    }
    else{
        cout<<"No"<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}