#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
#define double long double
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 1123456
#define INF LLONG_MAX
#define MOD 32416187567
#define cte 10002
#define MAX ULLONG_MAX

vector<int> are[112345];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        are[a].pb(b);are[b].pb(a);
    }
    int root=-1;
    for(int i=1;i<=n;i++){
        if(are[i].size()>2){
            if(root==-1)root=i;
            else{
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    if(root==-1){
        cout<<"Yes"<<endl;
        cout<<1<<endl;
        for(int i=1;i<=n;i++){
            if(are[i].size()==1)cout<<i<<" ";
        }
        cout<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    cout<<are[root].size()<<endl;
    for(int i=1;i<=n;i++){
        if(are[i].size()==1)cout<<root<<" "<<i<<endl;
    }
}