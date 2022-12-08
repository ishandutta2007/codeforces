#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define eps 1e-3
#define f first
#define s second
#define MAXN 512345
#define INF LLONG_MAX/4
#define double long double
#define MOD 1000000007

int sumdel[112345];
int sumtot[112345];

vector<int> cands[112345];

set<int> dels;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int su,sq;
        cin>>su>>sq;
        su--;
        cands[su].pb(sq);
        dels.insert(su);
    }
    for(int i=0;i<m;i++){
        sort(cands[i].begin(),cands[i].end());
    }
    int resp=0;
    while(dels.size()!=0){
        set<int> nxt;
        int tot=0;
        while(dels.size()!=0){
            int at=*dels.begin();
            //cout<<at<<" ";
            dels.erase(*dels.begin());
            if(cands[at].size()==0)continue;
            sumdel[at]+=cands[at][cands[at].size()-1];
            //cout<<"bota"<<" ";
            cands[at].pop_back();
            if(sumdel[at]>=0){
                nxt.insert(at);
                tot+=sumdel[at];
            }
        }
        //cout<<"prox "<<tot<<endl;
        resp=max(resp,tot);
        dels=nxt;
    }
    cout<<resp<<endl;
    
}