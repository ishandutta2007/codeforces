#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
typedef long double ld;
#define ratio sdgdsf
const int N = 2e5+7;
const ld eps = 1e-7;
ld S[N],divsum[N];
ll A[N],pref[N];

struct line{
    ld k;
    ld b;
    ld get(ld x){
        return ld(x)*k+b;
    }
    line(ld val_k,ld val_b){
        k = val_k;
        b = val_b;
    }
};
ld inter(line a,line b){
    return (b.b-a.b)/(a.k-b.k);
}
int n,k;
pair<ld,int> F(ld val){
    deque<pair<line,int> > V = {{line(0,0),0} };
    ld last = 0;
    for(int i = 1;i<=n;++i){
        while(V.size()>1 && V[0].first.get(divsum[i])>V[1].first.get(divsum[i])){
            V.pop_front();
        }
        ld ans = V.front().first.get(divsum[i])+S[i];
        last = ans;
        pair<line,int> add = {line(-pref[i],-S[i]+divsum[i]*pref[i]+ans+val),V.front().second+1};
        int sz = V.size();
        while(sz>1 && inter(V[sz-1].first,add.first)<inter(V[sz-2].first,V[sz-1].first)){
            V.pop_back();
            --sz;
        }
        V.push_back(add);
    }
    return {last,V.back().second};
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>k;
    --k;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
        pref[i] = pref[i-1]+A[i];
        S[i] = S[i-1]+ld(pref[i])/A[i];
        divsum[i] = divsum[i-1]+ld(1)/A[i];
    }

    ld cl = 0,cr = 1e17;
    for(int step = 0;step<=70;++step){
        ld mid = (cl+cr)/2;
        if (F(mid).second>k)
            cl = mid;
        else cr = mid;
    }
    cout<<fixed<<setprecision(10)<<F(cr).first-k*cr<<endl;
    return 0;
}