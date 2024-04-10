#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 2e5+7;
int A[N];
int side[N];
char gt(int s){
    return s==0?'L':'R';
}
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i)
        cin>>A[i];
    sort(A+1,A+1+n);
    int need = 0;
    for(int i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        if (ch=='L')
            side[i] = 0;
        else side[i] = 1;
        if (i>1 && side[i]!=side[i-1])
            ++need;
    }
    int ptr1 = n-need+1,ptr2 = n-need;
    int s1 = side[1]^1,s2 = side[1];
    for(int i = 1;i<=n;++i){
        if (i>1 && side[i]!=side[i-1]){
            s2^=1;
            cout<<A[++ptr2]<<' '<<gt(s2)<<endl;
        }
        else{
            s1^=1;
            cout<<A[--ptr1]<<' '<<gt(s1)<<endl;
        }
    }

}
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}