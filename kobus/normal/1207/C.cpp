#include <bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define f first
#define s second
#define pb push_back
#define MAXN 212345
#define pii pair<int,int>
#define pdd pair<double,double>
#define one 1
#define int long long
#define mp make_pair
#define ld long double


int32_t main(){

    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;
        string s2;
        s2+='0';
        for(int i=0;i<n-1;i++){
            if(s[i]=='0'&&s[i+1]=='0')s2+='0';
            else s2+='1';
        }
        s2+='0';
        //cout<<s2<<endl;
        vector<int> v;
        int curr=0;
        int resp=0;
        int ans=0;
        for(int i=0;i<=s2.size();i++){
            if(i==s2.size()||s2[i]=='1'){
                if(curr!=0){
                    v.pb(curr);
                    curr=0;
                }

                if(i!=s2.size())ans+=2*b;
            }
            else curr++;
        }
        //for(auto x:v)cout<<x<<" ";
        //cout<<endl;
        if(v.size()==1){
            cout<<v[0]*b+n*a<<endl;
            continue;
        }
        ans+=v[0]*b;
        ans+=v[v.size()-1]*b;
        ans+=2*a;
        for(int i=1;i<v.size()-1;i++){
            ans+=min(2*a+v[i]*b,v[i]*2*b);
        }
        ans+=n*a;
        cout<<ans<<endl;
    }

    return 0;
}