//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 2E5+7;
const ll INF = 1E9;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    if (n==1){
        cout<<s2<<endl;
        return 0;
    }
    if (s1[0]!=s2[0]){
        for(ll i = 1;i<=n;++i)
            cout<<1;
        cout<<endl;
        return 0;
    }
    ll flag = 0;
    for(ll i = 0;i<n;++i){
        if (s1[i]!=s2[i])
            flag = 1;
    }
    if (flag==0){
        cout<<s1<<endl;
        return 0;
    }
    if (s2[n-1]!='0'){
        cout<<s2<<endl;
        return 0;
    }
    string res = s2;
    if (s2[n-2]=='1'){
        res[n-1] = '1';
    }
    for(ll i = n-1;i>=0;--i){
        if (s2[i]=='0'){
            s2[i] = '1';
        }
        else{
            s2[i] = '0';
            break;
        }
    }
    flag = 0;
    for(ll i = 0;i<n;++i)
        if (s1[i]!=s2[i])
            flag = 1;
    if (flag)res[n-1] = '1';
    cout<<res<<endl;
    return 0;
}