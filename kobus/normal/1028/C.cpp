#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 212345
#define INF INT_MAX/2
#define MOD 1000000007
#define p 41
#define LOGMAXN 20

struct re{
    pii ll,rr;
};

re v[MAXN];
int n;

re inter(int no){
    re resp;
    resp.ll={-INF,-INF};
    resp.rr={INF,INF};
    for(int i=0;i<n;i++){
        if(i==no)continue;
        resp.ll.f=max(resp.ll.f,v[i].ll.f);
        resp.ll.s=max(resp.ll.s,v[i].ll.s);
        resp.rr.f=min(resp.rr.f,v[i].rr.f);
        resp.rr.s=min(resp.rr.s,v[i].rr.s);
    }
    return resp;
}

bool collapsed(re r){
    return r.ll.f>r.rr.f||r.ll.s>r.rr.s;
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(1);
    cout.setf(ios::fixed);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i].ll.f>>v[i].ll.s>>v[i].rr.f>>v[i].rr.s;
    }
    re resp;
    resp.ll={-INF,-INF};
    resp.rr={INF,INF};
    int a=-1,b=-1;
    for(int i=0;i<n;i++){
        resp.ll.f=max(resp.ll.f,v[i].ll.f);
        resp.ll.s=max(resp.ll.s,v[i].ll.s);
        resp.rr.f=min(resp.rr.f,v[i].rr.f);
        resp.rr.s=min(resp.rr.s,v[i].rr.s);
        if(collapsed(resp)){
            a=i;
            break;
        }
    }
    resp.ll={-INF,-INF};
    resp.rr={INF,INF};
    for(int i=n-1;i>=0;i--){
        resp.ll.f=max(resp.ll.f,v[i].ll.f);
        resp.ll.s=max(resp.ll.s,v[i].ll.s);
        resp.rr.f=min(resp.rr.f,v[i].rr.f);
        resp.rr.s=min(resp.rr.s,v[i].rr.s);
        if(collapsed(resp)){
            b=i;
            break;
        }
    }
    re resp1=inter(a);
    if(!collapsed(resp1)){
        cout<<resp1.ll.f<<" "<<resp1.ll.s<<endl;
        return 0;
    }
    re resp2=inter(b);
    cout<<resp2.ll.f<<" "<<resp2.ll.s<<endl;
    return 0;
}