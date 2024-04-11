#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 2123456
#define INF LLONG_MAX
#define MOD 999999599
#define cte 10002
#define MAX 21234

pii v[112345];

bool mk(pii a,pii b){
    if(a.f==0 || b.s==0)return 0;
    if(b.f==0 || a.f==0)return 1;
    return (b.s*a.f)>(b.f*a.s);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout.precision(11);
    //cout.setf(ios::fixed);

    int n;
    cin>>n;
    int resp=0;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int num=0;
        for(int j=0;j<s.size();j++){
            if(s[j]=='s'){
                v[i].f++;
                num++;
            }
            else{
                v[i].s++;
                resp+=num;
            }
        }
    }
    sort(v,v+n,mk);
    int num=0;
    for(int i=0;i<n;i++){
        resp+=v[i].s*num;
        num+=v[i].f;
    }
    cout<<resp<<endl;

    return 0;

}