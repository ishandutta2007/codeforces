#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1E5+7;
pair<int,int> A[N];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=m;++i){
        cin>>A[i].first>>A[i].second;
    }
    sort(A+1,A+1+m);

    int ptr = 1,prev = 0;
    vector<pair<int,int> > segms = {{1,1}};
    while(ptr<=m){
        if (segms.empty())
            break;
        int cur = A[ptr].first;
        vector<int> V;
        vector<pair<int,int>> events;
        if (cur!=prev+1){
            int beg = segms[0].first;
            segms.clear();
            segms.push_back({beg,n});
        }
        while(ptr<=m && A[ptr].first==cur){
            V.push_back(A[ptr].second);
            ++ptr;
        }
        V.push_back(n+1);
        vector<pair<int,int> > new_segms;
        int pos = 0;
        int l = 0;
        for(auto to:segms){
            to.first = max(to.first,l);
            while(pos<V.size() && to.first<=to.second){
                int l = to.first;
                int r = V[pos]-1;
                if (l<=r){
                    new_segms.push_back({l,1});
                    new_segms.push_back({r+1,-1});
                }
                to.first = max(to.first,V[pos]+1);
                ++pos;
            }
            l = to.first;
        }
        segms.clear();
        sort(new_segms.begin(),new_segms.end());
        int cnt = 0,last = -1;
        for(int i = 0;i<new_segms.size();++i){
            cnt+=new_segms[i].second;
            if (i+1<new_segms.size() && new_segms[i].first==new_segms[i+1].first)
                continue;
            if (cnt && last==-1)
                last = new_segms[i].first;
            if (!cnt && last!=-1){
                if (last<=new_segms[i].first-1)
                    segms.push_back({last,new_segms[i].first-1});
                last = -1;
            }
        }
        prev = cur;

    }
    if (prev==n)
        for(auto to:segms){
            if (to.second==n){
                cout<<n*2-2<<'\n';
                return;
            }
        }
    else if (!segms.empty()){
        cout<<n*2-2<<'\n';
        return;
    }
    cout<<"-1\n";
}
int main() {

    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}