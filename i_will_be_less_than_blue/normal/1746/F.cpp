#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rnd(time(NULL));
const int N=300100;
const int L=60;
const ll inf=1e18;
int type[N],l[N],r[N],k[N];
int a[N];
char b[N*2][L];
int s[L][N];
void upd(int ind,int pos,int x){
    for (;pos<N;pos|=pos+1) s[ind][pos]+=x;
}
int get(int ind,int pos){
    int sum=0;
    for (;pos>=0;pos&=pos+1,pos--) sum+=s[ind][pos];
    return sum;
}
void solve(){
    int n,q;cin>>n>>q;
    vector<int>cord;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        cord.push_back(a[i]);
    }
    for (int i=1;i<=q;i++){
        cin>>type[i];
        if (type[i]==1) cin>>l[i]>>k[i];
        else cin>>l[i]>>r[i]>>k[i];
    }
    for (int i=1;i<=q;i++){
        if (type[i]==1) cord.push_back(k[i]);
    }
    sort(cord.begin(),cord.end());
    cord.erase(unique(cord.begin(),cord.end()),cord.end());
    for (int i=1;i<=n;i++){
        a[i]=lower_bound(cord.begin(),cord.end(),a[i])-cord.begin()+1;
    }
    for (int i=1;i<=q;i++){
        if (type[i]==1){
            k[i]=lower_bound(cord.begin(),cord.end(),k[i])-cord.begin()+1;
        }
    }
    int m=cord.size();
    for (int i=1;i<=m;i++){
        for (int j=0;j<L;j++){
            b[i][j]=rnd()&1;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<L;j++) {
            upd(j,i,b[a[i]][j]);
        }
    }
    for (int i=1;i<=q;i++){
        if (type[i]==2){
            bool ok=true;
            for (int j=0;j<L;j++){
                ok&=((get(j,r[i])-get(j,l[i]-1))%k[i]==0);
            }
            if (ok) cout<<"YES\n";
            else cout<<"NO\n";
        } else {
            for (int j=0;j<L;j++){
                int add=b[k[i]][j]-b[a[l[i]]][j];
                if (add) upd(j,l[i],add);

            }
            a[l[i]]=k[i];
        }
    }




}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/**
10 8
1234 2 3 3 2 1 1 2 3 4
2 1 6 2
1 1 1
2 1 6 2
2 1 9 2
1 10 5
2 1 9 3
1 3 5
2 3 10 2

**/