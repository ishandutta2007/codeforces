#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define X first
#define Y second

const int N=150;
const int MOD=1e9+7;


int n,a[N][5];
int csuc[5];


bool check(int prob,int lv,int add){
    int base=1<<(lv+1);
    int L=(lv==5)?0:((n+add)/base+1);
    int R=(n+add)/(1<<lv);
    if (L>R) return 0;
    if (csuc[prob]<=R&&csuc[prob]+(a[1][prob]!=-1?add:0)>=L) return 1;
    return 0;
}
int cal(int prob,int lv){
    int ans=0;
    if (a[1][prob]!=-1) ans+=500*(lv+1)-2*(lv+1)*a[1][prob];
    if (a[2][prob]!=-1) ans-=500*(lv+1)-2*(lv+1)*a[2][prob];
    return ans;
}
bool DFS(int prob,int add,int diff){
    if (prob==5)
        return diff>0;
    bool ans=0;
    for(int i=0;i<6&&!ans;i++) if (check(prob,i,add))
        ans|=DFS(prob+1,add,diff+cal(prob,i));
    return ans;
}
int solve(){
    int ans=MOD+1;
    vector <int> can;
    can.push_back(0);
    for(int prob=0;prob<5;prob++){
        int suc=0;
        for(int i=1;i<=n;i++) suc+=a[i][prob]!=-1;
        csuc[prob]=suc;
        int lv=0;
        while (lv<5&&(suc<<(lv+1))<=n) lv++;
        if (a[1][prob]){
            ///decrease point
            for(int i=lv-1;i>=0;i--){
                int L=0,R=MOD;
                while (L<=R){
                    int mid=(L+R)/2;
                    if ((ll(suc+mid)<<(i+1))>(suc+n)) R=mid-1;
                    else L=mid+1;
                }
                can.push_back(L);
            }
        }
        ///increase point
        for(int i=lv+1;i<6;i++)
            can.push_back((suc<<i)-n);
    }
    for(auto i:can)
        if (DFS(0,i,0)) ans=min(ans,i);
    if (ans==MOD+1) return -1;
    return ans;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=0;j<5;j++) cin>>a[i][j];
    cout<<solve();
}