// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
void A(){
    cout<<"tokitsukaze"<<endl;
    exit(0);
}
void B(){
    cout<<"quailty"<<endl;
    exit(0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    set<int> p[2];
    for(int i=0;i<n;++i){
        p[s[i]-'0'].insert(i);
    }
    int m[2],M[2];
    if(p[0].empty()||p[1].empty()){
        A();
    }
    m[0]=*p[0].begin();
    M[0]=*--p[0].end();
    m[1]=*p[1].begin();
    M[1]=*--p[1].end();
    if(M[0]-m[0]+1<=k||M[1]-m[1]+1<=k){
        A();
    }
    bool b=true;
    for(int i=0;i<n-k+1;++i){
        bool ok=false;
        int l,r;
        l=min(m[0],i);
        r=max(M[0],i+k-1);
        if(r-l+1<=k){
            ok=true;
        }
        if(m[1]<i){
            l=m[1];
        }else{
            l=*p[1].lower_bound(i+k);
        }
        if(M[1]>=i+k){
            r=M[1];
        }else{
            r=*--p[1].lower_bound(i);
        }
        if(r-l+1<=k){
            ok=true;
        }
        if(!ok){
            b=false;
        }
        ok=false;
        l=min(m[1],i);
        r=max(M[1],i+k-1);
        if(r-l+1<=k){
            ok=true;
        }
        if(m[0]<i){
            l=m[0];
        }else{
            l=*p[0].lower_bound(i+k);
        }
        if(M[0]>=i+k){
            r=M[0];
        }else{
            r=*--p[0].lower_bound(i);
        }
        if(r-l+1<=k){
            ok=true;
        }
        if(!ok){
            ok=false;
        }
    }
    if(b){
        B();
    }
    cout<<"once again"<<endl;
    return 0;
}