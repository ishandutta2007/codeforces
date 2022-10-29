#include <bits/stdc++.h>

#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define mi          map<int,int>
#define mii         map<int,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,q;
int vis[10000000],hsh[10000000];
vector<pair<pii,pii>> v;
int tree[30000006],lazy[30000006];
void upd(int &a,int b){
    a+=b;
}
void upd2(int node,int l1,int r1,int l2,int r2,int val){
    if(l1!=l2){
        if(r1!=r2){
            upd(lazy[node<<2|1],val);
            upd(lazy[node<<2|2],val);
            upd(lazy[node<<2|3],val);
            upd(lazy[(node<<2)+4],val);
        }
        else{
            upd(lazy[node<<2|1],val);
            upd(lazy[node<<2|3],val);
        }
    }
    else{
        if(r1!=r2){
            upd(lazy[node<<2|1],val);
            upd(lazy[node<<2|2],val);
        }
    }
}
void update(int node,int l1,int r1,int l2,int r2,int x1,int y1,int x2,int y2,int val){
    if(lazy[node]!=0){
        upd(tree[node],lazy[node]);
        upd2(node,l1,r1,l2,r2,lazy[node]);
        lazy[node]=0;
    }
    if(x1>l2 || x2<l1 || y1>r2 || y2<r1) return;
    if(x1<=l1 && x2>=l2 && y1<=r1 && y2>=r2){
        upd(tree[node],val);
        upd2(node,l1,r1,l2,r2,val);
        return ;
    }
    if(l1!=l2){
        if(r1!=r2){
            int lmid=(l1+l2)>>1,rmid=(r1+r2)>>1;
            update(node<<2|1,l1,r1,lmid,rmid,x1,y1,x2,y2,val);
            update(node<<2|2,l1,rmid+1,lmid,r2,x1,y1,x2,y2,val);
            update(node<<2|3,lmid+1,r1,l2,rmid,x1,y1,x2,y2,val);
            update((node<<2)+4,lmid+1,rmid+1,l2,r2,x1,y1,x2,y2,val);
        }
        else{
            int lmid=(l1+l2)>>1;
            update(node<<2|1,l1,r1,lmid,r1,x1,y1,x2,y2,val);
            update(node<<2|3,lmid+1,r1,l2,r2,x1,y1,x2,y2,val);
        }
    }
    else{
        if(r1!=r2){
            int rmid=(r1+r2)>>1;
            update(node<<2|1,l1,r1,l1,rmid,x1,y1,x2,y2,val);
            update(node<<2|2,l1,rmid+1,l2,r2,x1,y1,x2,y2,val);
        }
    }
}
int query(int node,int l1,int r1,int l2,int r2,int x1,int y1,int x2,int y2){
    if(x1>l2 || x2<l1 || y1>r2 || y2<r1) return 0;
    if(lazy[node]!=0){
        upd(tree[node],lazy[node]);
        upd2(node,l1,r1,l2,r2,lazy[node]);
        lazy[node]=0;
    }
    if(x1<=l1 && x2>=l2 && y1<=r1 && y2>=r2) return tree[node];
    if(l1!=l2){
        if(r1!=r2){
            int lmid=(l1+l2)>>1,rmid=(r1+r2)>>1;
            int q1=query(node<<2|1,l1,r1,lmid,rmid,x1,y1,x2,y2);
            int q2=query(node<<2|2,l1,rmid+1,lmid,r2,x1,y1,x2,y2);
            int q3=query(node<<2|3,lmid+1,r1,l2,rmid,x1,y1,x2,y2);
            int q4=query((node<<2)+4,lmid+1,rmid+1,l2,r2,x1,y1,x2,y2);
            upd(q1,q2);
            upd(q1,q3);
            upd(q1,q4);
            return q1;            
        }
        else{
            int lmid=(l1+l2)>>1;
            int q1=query(node<<2|1,l1,r1,lmid,r1,x1,y1,x2,y2);
            int q3=query(node<<2|3,lmid+1,r1,l2,r2,x1,y1,x2,y2);
            upd(q1,q3);
            return q1;                        
        }
    }
    else{
        if(r1!=r2){
            int rmid=(r1+r2)>>1;
            int q1=query(node<<2|1,l1,r1,l1,rmid,x1,y1,x2,y2);
            int q2=query(node<<2|2,l1,rmid+1,l2,r2,x1,y1,x2,y2);
            upd(q1,q2);
            return q1;                        
        }
    }
}
void solve(){
    srand(20001206);
    cin>>n>>m>>q;
    while(q--){
        int t,x1,x2,y1,y2;
        cin>>t>>x1>>y1>>x2>>y2;
        int hh=x1+y1*10+x2*100+y2*1000;
        if(t==1){
            vis[hh]++;
            v.pb({{x1,y1},{x2,y2}});
        }
        else if(t==2){
            vis[hh]--;
            v.pb({{x1,y1},{x2,y2}});
        }
        else{
            for(auto i:v){
                int r=i.x.x+i.x.y*10+i.y.x*100+i.y.y*1000;
                if(vis[r]){
                    update(0,1,1,n,m,i.x.x,i.x.y,i.y.x,i.y.y,r*vis[r]);
                    vis[r]=0;
                }
            }
            v.clear();
            auto q1=query(0,1,1,n,m,x1,y1,x1,y1);
            auto q2=query(0,1,1,n,m,x2,y2,x2,y2);
            if(q1!=q2){
                cout<<"No\n";
            }
            else cout<<"Yes\n";
        }
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