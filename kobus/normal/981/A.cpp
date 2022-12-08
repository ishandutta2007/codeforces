#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
#define double long double
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 1123456
#define INF LLONG_MAX
#define MOD 32416187567
#define cte 10002
#define MAX ULLONG_MAX

string s;

bool ispal(string s){
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1])return 0;
    }
    return 1;
}

string subs(int i, int j){
    string ans="";
    for(int k=i;k<=j;k++)ans.pb(s[k]);
    return ans;
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    cin>>s;
    int resp=0;
    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            if(!ispal(subs(i,j)))resp=max(resp,j-i+1); 
        }
    }

    cout<<resp<<endl;


}