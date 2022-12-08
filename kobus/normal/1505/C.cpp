#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define MAXN 112345
#define MOD 1000000007
#define f first
#define s second
#define pii pair<long long, long long>
#define INF LLONG_MAX/1000
#define int long long

int32_t main(){
    //cin.tie(NULL);
    //ios::sync_with_stdio(false);
    int num=0;
    string s;
    cin>>s;
    for(int i=2;i<s.size();i++){
        if(s[i]-'A'!=(s[i-1]+s[i-2]-2*'A')%26){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;

    return 0;
}