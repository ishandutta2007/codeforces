#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int DIM = 5007;

int solve(){
    int n;
    cin>>n;
    int sum = 0,r = 1,cnt = 0;
    while(sum<n){
        sum+=r;
        ++cnt;
        r+=2;
    }
    cout<<cnt<<endl;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        assert(solve());
    return 0;
}