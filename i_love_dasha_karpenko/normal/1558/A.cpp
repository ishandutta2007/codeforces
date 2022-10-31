#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int a,b;
int F(int g1,int g2,int k){
    int w1 = a+g1-k;
    int w2 = b+g2-k;
    if (w1%2 || w2%2 || w1<0 || w2<0)
        return 0;
    w1/=2;
    w2/=2;
    int b1 = a-w1;
    int b2 = b-w2;
    if (b1<0 || b2<0)
        return 0;
    return 1;
}
int Check(int val){
    int cnt1 = (a+b)/2;
    int cnt2 = a+b-cnt1;
    return F(cnt1,cnt2,val) || F(cnt2,cnt1,val);
}
void solve(){

    cin>>a>>b;
    vector<int> ans;
    for(int i = 0;i<=a+b;++i){
        if (Check(i))
            ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(auto to:ans)
        cout<<to<<' ';
    cout<<endl;
}
int main() {
    int t;
    t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}