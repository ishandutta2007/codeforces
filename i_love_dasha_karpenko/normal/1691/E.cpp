#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e5+7;
struct event{
    int pos,ind,col;
} A[N*2];
bool mc(event a,event b){
    return a.pos<b.pos;
}
int P[N],groups,lim[N];
int F(int x){
    if (x==P[x]){
        return x;
    }
    P[x] = F(P[x]);
    return P[x];
}
void unite(int a,int b){
    a = F(a);
    b = F(b);
    if (a==b){
        return;
    }
    groups -= 1;
    P[a] = b;
}
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i+=1){
        int c,l,r;
        cin>>c>>l>>r;
        lim[i] = r;
        A[i*2-1] = {l,i,c};
        A[i*2] = {r+1,-i,c};
    }
    sort(A+1,A+1+n*2,mc);
    for(int i = 1;i<=n;i+=1){
        P[i] = i;
    }
    groups = n;
    set<int> S[2];
    for(int i = 1;i<=n*2;){
        int point = A[i].pos;
        while(A[i].pos==point){
            if (A[i].ind<0){
                S[A[i].col].erase(-A[i].ind);
            }
            else{
                S[A[i].col].insert(A[i].ind);
            }
            i += 1;
        }
        if (!S[0].empty() && !S[1].empty()){
            for(int c = 0;c<2;c+=1) {
                while (S[c].size() > 1) {
                    unite(*S[c].begin(), *prev(S[c].end()));
                    if (lim[*S[c].begin()]>lim[*S[c].rbegin()]) {
                        S[c].erase(prev(S[c].end()));
                    }
                    else{
                        S[c].erase(S[c].begin());
                    }
                }
            }
            unite(*S[0].begin(),*S[1].begin());
        }
    }
    cout<<groups<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}