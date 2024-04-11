#include <bits/stdc++.h>
using namespace std;

#define MAXN 212345
#define int long long
#define pb push_back
#define inf LLONG_MAX
#define mp make_pair
#define pii pair<int,int>
#define f first
#define s second

struct valor{
    int val;
    int qte;
    int blw;
    int abv;
    int sblw;
    int sabv;
};

map<int,int> m;

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        m[x]++;
    }
    vector<valor> v;
    for(auto x:m){
        valor vv;
        vv.val=x.f;
        vv.qte=x.s;
        v.pb(vv);
    }
    v[0].blw=0;
    v[0].sblw=0;
    for(int i=1;i<(int)v.size();i++){
        v[i].blw=v[i-1].blw+v[i-1].qte;
        v[i].sblw=v[i-1].sblw+(v[i].val-v[i-1].val)*v[i].blw;
    }
    v[((int)v.size())-1].abv=0;
    v[((int)v.size())-1].sabv=0;
    for(int i=((int)v.size())-2;i>=0;i--){
        v[i].abv=v[i+1].abv+v[i+1].qte;
        v[i].sabv=v[i+1].sabv+(v[i+1].val-v[i].val)*v[i].abv;
    }
    int resp=inf;
    for(int i=0;i<(int)v.size();i++){
        if(v[i].qte>=k){
            resp=0;
            break;
        }
        if(v[i].blw+v[i].qte>=k){
            int kr=k-v[i].qte;
            int respar=v[i].sblw-(v[i].blw-kr);
            resp=min(resp,respar);
        }
        else{
            int kr=k-v[i].qte-v[i].blw;
            int respar=v[i].sblw;
            respar+=v[i].sabv-(v[i].abv-kr);
            resp=min(resp,respar);
        }

         if(v[i].abv+v[i].qte>=k){
            int kr=k-v[i].qte;
            int respar=v[i].sabv-(v[i].abv-kr);
            resp=min(resp,respar);
        }
        else{
            int kr=k-v[i].qte-v[i].abv;
            int respar=v[i].sabv;
            respar+=v[i].sblw-(v[i].blw-kr);
            resp=min(resp,respar);
        }

    }

    cout<<resp<<endl;

    
    
    return 0;
 
}