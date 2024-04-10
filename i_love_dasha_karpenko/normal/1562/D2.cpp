#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 3e5+7;

int A[N],pref[N];
vector<int> V[N*2];
void solve(){
    int n,q;
    cin>>n>>q;
    for(int i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        if (ch=='-')
            A[i] = -1;
        else A[i] = 1;
        pref[i] = pref[i-1]+(i%2==0?-A[i]:A[i]);
        V[pref[i]+n].push_back(i);
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        int df = abs(pref[r]-pref[l-1]);
        if (df==0)
            cout<<"0\n";
        else if (df%2){
            cout<<"1\n";
            int need;
            if (pref[l-1]<pref[r]){
                need = pref[l-1]+df/2+1;
            }
            else{
                need = pref[l-1]-(df/2+1);
            }
            int pos = lower_bound(V[need+n].begin(),V[need+n].end(),l)-V[need+n].begin();
            if (V[need+n][pos]>r)
                n/=0;
            cout<<V[need+n][pos]<<endl;
        }
        else {
            cout<<"2\n";
            df = abs(pref[r-1]-pref[l-1]);
            --r;
            int need;
            if (pref[l-1]<pref[r]){
                need = pref[l-1]+df/2+1;
            }
            else{
                need = pref[l-1]-(df/2+1);
            }
            int pos = lower_bound(V[need+n].begin(),V[need+n].end(),l)-V[need+n].begin();
            if (V[need+n][pos]>r)
                n/=0;
            cout<<V[need+n][pos]<<' '<<r+1<<endl;
        }
    }
    for(int i = 0;i<=n*2;++i)
        V[i].clear();
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}