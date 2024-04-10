#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 2e4+7;

int A[N];

void solve(){
    int n;
    cin>>n;
    int pos = 0,split = n/2;
    for(int i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        A[i] = ch-'0';
        if (pos==0 && i>split && A[i]==0){
            pos = i;
        }
    }
    if (pos!=0){
        cout<<1<<' '<<pos<<' '<<1<<' '<<pos-1<<endl;
        return;
    }
    if (A[split]==0){
        cout<<split<<' '<<n<<' '<<split+1<<' '<<n<<endl;
    }
    else{
        cout<<split<<' '<<n-1<<' '<<split+1<<' '<<n<<endl;
    }

}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}