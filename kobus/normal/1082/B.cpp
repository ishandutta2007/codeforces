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


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    int n;
    string s;
    cin>>n>>s;
    int gold=0;
    int silver=0;
    for(int i=0;i<n;i++){
        if(s[i]=='G')gold++;
        else silver++;
    }
    vector<pair<int,char>> v;
    int seq=1;
    for(int i=0;i<n;i++){
        if(i==n-1 || s[i]!=s[i+1]){
            v.pb(mp(seq,s[i]));
            seq=1;
        }
        else seq++;
    }
    int resp=0;
    for(int i=0;i<v.size();i++){
        if(v[i].s=='G'){
            if(v[i].f==gold)resp=max(resp,v[i].f);
            else resp=max(resp,v[i].f+1);
        }
        if(i!=0 && i!=v.size()-1 && v[i]==mp(1ll,'S')){
            if(v[i-1].f+v[i+1].f==gold)resp=max(resp,v[i-1].f+v[i+1].f);
            else resp=max(resp,v[i-1].f+v[i+1].f+1);
        }
    }
    cout<<resp<<endl;
}