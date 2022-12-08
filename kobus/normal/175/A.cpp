#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define eps 1e-3
#define f first
#define s second
#define MAXN 512345
#define INF LLONG_MAX/4
#define double long double
#define MOD 1000000007

bool valid(string s){
    if(s.size()==0)return 0;
    if(s.size()==1)return 1;
    if(s[0]=='0')return 0;
    if(s=="1000000")return 1;
    if(s.size()<=6)return 1;
    return 0;
}

string cr(int i,int j, string s){
    string resp;
    for(int k=i;k<=j;k++)resp.pb(s[k]);
    return resp;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    string s;
    cin>>s;
    int resp=-1;
    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size()-1;j++){
            //cout<<i<<" "<<j<<endl;
            //cout<<cr(0,i,s)<<" "<<cr(i+1,j,s)<<" "<<cr(j+1,s.size()-1,s)<<endl;
            if(valid(cr(0,i,s))&&valid(cr(i+1,j,s))&&valid(cr(j+1,s.size()-1,s)))
                resp=max(resp,(int)stoi(cr(0,i,s))+stoi(cr(i+1,j,s))+stoi(cr(j+1,s.size()-1,s)));
        }
    }
    cout<<resp<<endl;
}