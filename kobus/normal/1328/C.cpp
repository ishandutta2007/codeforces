#include <bits/stdc++.h>
using namespace std;

#define MAXN 1123456
#define int long long
#define pb push_back
#define inf INT_MAX
#define mp make_pair
#define pii pair<int,int>
#define f first
#define s second


pair<string,string> res(string s){
    int i=0;
    string s1;
    string s2;
    while(i<s.size()&&s[i]=='2'||s[i]=='0'){
        if(s[i]=='2'){
            s1.pb('1');
            s2.pb('1');
        }
        else{
            s1.pb('0');
            s2.pb('0');
        }
        i++;
    }
    if(i<s.size()){
        s1.pb('0');
        s2.pb('1');
        i++;
    }
    while(i<s.size()){
        s1.pb(s[i]);
        s2.pb('0');
        i++;
    }
    return mp(s1,s2);
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        pair<string,string> ans=res(s);
        cout<<ans.f<<endl<<ans.s<<endl;
    
    }
    return 0;
 
}