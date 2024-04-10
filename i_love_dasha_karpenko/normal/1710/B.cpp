#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
//#define int ll
const int N = 2e5+7;
const ll INF = 1e18;
pair<int,int> A[N];
int P[N*3];
ll clk[N*3],pref[N*3],suf[N*3];
vector<int> V[N*3];
bool ans[N];
struct tree{
    ll T[N*6];
    void buildtree(int t,int tl,int tr,ll *A){
        if (tl==tr){
            T[t] = A[tl];
            return;
        }
        int tm = (tl+tr)/2;
        buildtree(t+1,tl,tm,A);
        buildtree(t+(tm-tl+1)*2,tm+1,tr,A);
        T[t] = max(T[t+1],T[t+(tm-tl+1)*2]);
    }
    ll get(int t,int tl,int tr,int l,int r){
        if (l>tr || tl>r){
            return -INF;
        }
        if (l<=tl && tr<=r){
            return T[t];
        }
        int tm = (tl+tr)/2;
        return max(get(t+1,tl,tm,l,r),get(t+(tm-tl+1)*2,tm+1,tr,l,r));
    }
} L,R,NT;
void solve(){
    int n,m;
    cin>>n>>m;
    set<int> S;
    //cout<<"G\n";
    for(int i = 1;i<=n;i+=1){
        cin>>A[i].first>>A[i].second;
        S.insert(A[i].first);
        S.insert(A[i].first-A[i].second);
        S.insert(A[i].first+A[i].second);
    }
    map<int,int> M;
    int ptr = 0;
    for(int to:S){
        ptr += 1;
        P[ptr] = to;
        M[to] = ptr;
    }
    for(int i = 1;i<=n;i+=1){
        V[M[A[i].first]].push_back(i);
    }
    ll sum = 0;
    priority_queue<int,vector<int>,greater<int> > Q;
    for(int i = 1;i<=ptr;i+=1){
        for(int ind:V[i]){
            sum += A[ind].second + A[ind].first;
            Q.push(A[ind].first+A[ind].second);
        }
        while(!Q.empty() && Q.top()<=P[i]){
            sum -= Q.top();
            Q.pop();
        }
        ll cnt = Q.size();
        clk[i] += sum - cnt*P[i];
        //if (P[i]==1){
            //cout<<"FFF "<<sum<<' '<<cnt<<endl;;
        //}

    }
    while(!Q.empty()){
        Q.pop();
    }
    sum = 0;
    priority_queue<int> BQ;
    for(int i = ptr;i>=1;i-=1){

        while(!BQ.empty() && BQ.top()>=P[i]){
            sum += BQ.top();
            BQ.pop();
        }
        ll cnt = BQ.size();
        clk[i] += sum + cnt*P[i];
//        if (P[i]==-1){
//            cout<<"FFFF "<<sum<<' '<<cnt<<' '<<BQ.top()<<endl;
//        }
        for(int ind:V[i]){
            sum += A[ind].second-A[ind].first;
            BQ.push(A[ind].first-A[ind].second);
        }
    }
    for(int i = 1;i<=ptr;i+=1){
        pref[i] = clk[i]-P[i];
        //cout<<"D "<<P[i]<<' '<<clk[i]<<endl;
    }
    for(int i = ptr;i>=1;i-=1){
        suf[i] = clk[i]+P[i];
    }
    L.buildtree(0,1,ptr,pref);
    R.buildtree(0,1,ptr,suf);
    NT.buildtree(0,1,ptr,clk);
    for(int i = 1;i<=ptr;i+=1){
        for(int ind:V[i]){
            int lpos = lower_bound(P+1,P+1+ptr,A[ind].first-A[ind].second)-P;
            int rpos = upper_bound(P+1,P+1+ptr,A[ind].first+A[ind].second)-P-1;
            ll v = max({NT.get(0,1,ptr,1,lpos-1),NT.get(0,1,ptr,rpos+1,ptr),
                       L.get(0,1,ptr,lpos,i)+P[i]-A[ind].second,R.get(0,1,ptr,i,rpos)-P[i]-A[ind].second});
            //cout<<ind<<' '<<v<<endl;
            ans[ind] = v<=m;
        }
    }
    for(int i = 1;i<=n;i+=1){
        cout<<ans[i];
    }
    cout<<endl;
    for(int i = 1;i<=n;i+=1){
        ans[i] = 0;
    }
    for(int i = 1;i<=ptr;i+=1){
        V[i].clear();
        clk[i] = pref[i] = suf[i] = P[i] = 0;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
    return 0;
}