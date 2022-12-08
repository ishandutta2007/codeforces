#include <bits/stdc++.h>
using namespace std;
#define INF 1'000'000'000'010
#define double long double
#define f first
#define s second
#define eps 1e-11
#define pb push_back
#define MAXN 1123

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(5);
    cout.setf(ios::fixed);

    vector<int> a;
    vector<int> b;
    vector<int> c;
    vector<int> d;

    int n;cin>>n;
    string as,bs;
    cin>>as>>bs;
    for(int i=0;i<n;i++){
        if(as[i]=='0'&&bs[i]=='0')a.pb(i);
        if(as[i]=='0'&&bs[i]=='1')b.pb(i);
        if(as[i]=='1'&&bs[i]=='0')c.pb(i);
        if(as[i]=='1'&&bs[i]=='1')d.pb(i);
    }
    for(int i=0;i<=n/2;i++){
        vector<int> ans;
        int au=0,bu=0,cu=0,du=0;
        bool fudeu=0;
        while(ans.size()<i){
            if(cu<c.size()){
                ans.pb(c[cu]);
                cu++;
            }
            else if(du<d.size()){
                ans.pb(d[du]);
                du++;
            }
            else{
                fudeu=1;
                break;
            }
        }
        if(fudeu)continue;
        while(ans.size()<n/2){
            if(bu<b.size()){
                ans.pb(b[bu]);
                bu++;
            }
            else if(au<a.size()){
                ans.pb(a[au]);
                au++;
            }
            else{
                fudeu=1;
                break;
            }
        }
        if(fudeu)continue;
        if((d.size()-du+b.size()-bu)==i && (a.size()-au+c.size()-cu)==n/2-i){
            for(int i=0;i<ans.size();i++){
                cout<<ans[i]+1<<" ";
            }
            cout<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}