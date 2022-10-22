//
// Created by hydd on 2022/7/17.
//
#include<bits/stdc++.h>
using namespace std;
int n,q,a[110000],Log2[110000];
struct node{
    int mn,mx;
    node(){}
    node(int _mn,int _mx):mn(_mn),mx(_mx){}
    node operator+(const node &a) const{
        return node(min(mn,a.mn),max(mx,a.mx));
    }
} val[19][19][110000];
node query(int k,int l,int r){
    if (l>=r) return node(n,1);
    r--; int K=Log2[r-l+1];
    return val[k][K][l]+val[k][K][r-(1<<K)+1];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>q; Log2[0]=-1;
    for (int i=1;i<=n;i++) Log2[i]=Log2[i>>1]+1;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int k=0;k<=18;k++){
        if (k) for (int i=1;i<n;i++) val[k][0][i]=query(k-1,val[k-1][0][i].mn,val[k-1][0][i].mx);
        else for (int i=1;i<n;i++) val[k][0][i]=node(min(a[i],a[i+1]),max(a[i],a[i+1]));
        for (int j=1;(1<<j)<n;j++)
            for (int i=1;i+(1<<j)-1<n;i++)
                val[k][j][i]=val[k][j-1][i]+val[k][j-1][i+(1<<(j-1))];
    }
    int l,r;
    while (q--){
        cin>>l>>r; int ans=0;
        if (l==1&&r==n){
            cout<<"0\n";
            continue;
        }
        for (int i=18;i>=0;i--){
            node res=query(i,l,r);
            if (res.mn!=1||res.mx!=n){
                l=res.mn; r=res.mx;
                ans|=(1<<i);
            }
        }
        if (ans>2e5) cout<<"-1\n";
        else cout<<ans+1<<'\n';
    }
    return 0;
}