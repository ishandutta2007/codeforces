#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m;
vii v1,v2;
set<int> a1,a2;
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        v1.pb({min(x,y),max(x,y)});
    }
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        v2.pb({min(x,y),max(x,y)});
    }
    rep(i,0,n){
        set<int> s1;
        rep(k,0,m){
            if(v1[i]==v2[k]) continue;
            multiset<int> s;
            s.insert(v1[i].x);
            s.insert(v1[i].y);
            s.insert(v2[k].x);
            s.insert(v2[k].y);
            if(s.count(v1[i].x)==2){
                s1.insert(v1[i].x);
            }
            if(s.count(v1[i].y)==2){
                s1.insert(v1[i].y);
            }
        }
        if(sz(s1)>1){
            cout<<-1<<endl;
            return;
        }
        if(sz(s1)==1){
            a1.insert(*s1.begin());
        }
    }
    swap(v1,v2);
    rep(i,0,m){
        set<int> s1;
        rep(k,0,n){
            if(v1[i]==v2[k]) continue;
            multiset<int> s;
            s.insert(v1[i].x);
            s.insert(v1[i].y);
            s.insert(v2[k].x);
            s.insert(v2[k].y);
            if(s.count(v1[i].x)==2){
                s1.insert(v1[i].x);
            }
            if(s.count(v1[i].y)==2){
                s1.insert(v1[i].y);
            }
        }
        if(sz(s1)>1){
            cout<<-1<<endl;
            return;
        }
        if(sz(s1)==1){
            a2.insert(*s1.begin());
        }
    }
    if(sz(a1)==1 and sz(a2)==1){
        cout<<*a1.begin()<<endl;
    }
    else{
        cout<<0<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}