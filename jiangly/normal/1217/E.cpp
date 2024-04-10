#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int a[2];
    Node():a{INT_MAX,INT_MAX}{}
};
Node operator + (const Node &p,const Node &q){
    Node ans;
    if(p.a[0]<q.a[0]){
        ans.a[0]=p.a[0];
        ans.a[1]=min(p.a[1],q.a[0]);
    }else{
        ans.a[0]=q.a[0];
        ans.a[1]=min(q.a[1],p.a[0]);
    }
    return ans;
}
class SegTree{
private:
    int sz;
    vector<Node> a;
    Node query(int p,int l,int r,int x,int y){
        if(l>=y||r<=x){
            return Node();
        }
        if(l>=x&&r<=y){
            return a[p];
        }
        return query(p*2,l,(l+r)/2,x,y)+query(p*2+1,(l+r)/2,r,x,y);
    }
public:
    SegTree(int n){
        sz=1;
        while(sz<n){
            sz*=2;
        }
        a.resize(sz*2);
    }
    void modify(int x,int y){
        a[x+sz].a[0]=y;
        for(int i=(x+sz)/2;i!=0;i/=2){
            a[i]=a[i*2]+a[i*2+1];
        }
    }
    Node query(int l,int r){
        return query(1,0,sz,l,r);
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    vector<SegTree> t(9,SegTree(n));
    for(int i=0;i<n;++i){
        for(int x=a[i],k=0;k<9;++k,x/=10){
            if(x%10>0){
                t[k].modify(i,a[i]);
            }else{
                t[k].modify(i,INT_MAX);
            }
        }
    }
    while(m--){
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1){
            --x;
            a[x]=y;
            for(int v=y,k=0;k<9;++k,v/=10){
                if(v%10>0){
                    t[k].modify(x,a[x]);
                }else{
                    t[k].modify(x,INT_MAX);
                }
            }
        }else{
            --x;
            int ans=INT_MAX;
            for(int k=0;k<9;++k){
                Node a=t[k].query(x,y);
                if(a.a[1]!=INT_MAX){
                    ans=min(ans,a.a[0]+a.a[1]);
                }
            }
            if(ans==INT_MAX){
                cout<<-1<<endl;
            }else{
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}