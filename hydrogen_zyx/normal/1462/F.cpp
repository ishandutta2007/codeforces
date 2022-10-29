#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll mod = 1e9+7;
const ll inf = 0x3f3f3f3f3f3f3f3f;

struct line{
    int s,t,n;
    bool operator<(const line& a)const {
        return t>a.t;
    }
};
bool cmp(line a,line b){
    return a.s<b.s;
}
line a[N];
vector<int> v;
int bit[N];
void padd(int k,int x){
    while(k<N){
        bit[k]+=x;
        k+=k&-k;
    }
}
void add(int l,int r,int x){
    padd(l,x);
    padd(r+1,-x);
}
int query(int k){
    int ans=0;
    while(k){
        ans+=bit[k];
        k-=k&-k;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        v.clear();
        for(int i=0;i<=n+5;i++) bit[i]=0;
        for(int i=1;i<=n;i++) {
            cin>>a[i].s>>a[i].t;
            v.push_back(a[i].s);
            v.push_back(a[i].t);
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        for(int i=1;i<=n;i++){
            a[i].s=lower_bound(v.begin(),v.end(),a[i].s)-v.begin()+1;
            a[i].t=lower_bound(v.begin(),v.end(),a[i].t)-v.begin()+1;
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++) a[i].n=i;
        int ans=0;
        int p=1;
        priority_queue<line> que;
        for(int i=1;i<=2*n+5;i++){
            while(p<=n&&a[p].s<=i) {
                que.push(a[p]);
                add(p,p,que.size());
                add(1,p-1,1);
                p++;
            }
            while(!que.empty()&&que.top().t<=i){
                ans=max(ans,query(que.top().n));
                que.pop();
            }
        }
        while(!que.empty()){
            ans=max(ans,query(que.top().n));
            que.pop();
        }
        cout<<n-ans<<endl;
    }
}