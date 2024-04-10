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
int a,b,c,d;
vii v1,v2;
char m[51][51];
void solve(){
    cin>>a>>b>>c>>d;
    rep(i,0,50){
        rep(j,0,26){
            if(i%2==0){
                if(j%2){
                    m[i][j]='A';
                }
                else{
                    v1.pb({i,j});
                }
            }
            else{
                m[i][j]='A';
            }
        }
    }
    rep(i,0,50){
        rep(j,26,50){
            if(i%2){
                if(j%2==0){
                    m[i][j]='B';
                }
                else{
                    v2.pb({i,j});
                }
            }
            else{
                m[i][j]='B';
            }
        }
    }
    a--;
    int cur1=0,cur2=0;
    while(cur2<a){
        m[v2[cur2].x][v2[cur2].y]='A';
        cur2++;
    }
    b--;
    while(cur1<b){
        m[v1[cur1].x][v1[cur1].y]='B';
        cur1++;
    }
    while(c){
        m[v1[cur1].x][v1[cur1].y]='C';
        cur1++;
        c--;        
    }
    while(d){
        m[v2[cur2].x][v2[cur2].y]='D';
        cur2++;
        d--;        
    }
    while(cur1<sz(v1)){
        m[v1[cur1].x][v1[cur1].y]='A';
        cur1++;
    }
    while(cur2<sz(v2)){
        m[v2[cur2].x][v2[cur2].y]='B';
        cur2++;
    }
    cout<<50<<" "<<50<<endl;
    rep(i,0,50){
        rep(j,0,50){
            cout<<m[i][j];
        }
        cout<<endl;
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