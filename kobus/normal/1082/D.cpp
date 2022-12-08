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

int dg[512];
bool chain[512];

vector<pii> ans;
int diam=0;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    int n;
    cin>>n;

    for(int i=0;i<n;i++)cin>>dg[i];
    int com=-1,fim=-1;
    for(int i=0;i<n;i++){
        if(dg[i]==1 && com==-1){
            com=i;
        }
        else if(dg[i]==1 && fim==-1){
            fim=i;
        }
    }
    if(com==-1){
        com=0;fim=1;
    }
    if(fim==-1 && com==0)fim=1;
    if(fim==-1)fim=0;

    //cout<<com+1<<" "<<fim+1<<endl;
    int last=com;
    for(int i=0;i<n;i++){
        if(dg[i]>=2 && i!=com && i!=fim){
            ans.pb(mp(last,i));
            dg[i]--;
            dg[last]--;
            chain[i]=1;
            chain[last]=1;
            last=i;
            diam++;
        }
    }
    ans.pb(mp(last,fim));
    dg[fim]--;
    dg[last]--;
    chain[fim]=1;
    chain[last]=1;
    diam++;
    for(int i=0;i<n;i++){
        //cout<<i+1<<" "<<dg[i]<<" "<<chain[i]<<endl;
    }
    for(int i=0;i<n;i++){
        if(!chain[i]){
            bool found=0;
            for(int j=0;j<n;j++){
                if(chain[j] && i!=j && dg[j]>0){
                    dg[j]--;
                    dg[i]--;
                    chain[i]=1;
                    chain[j]=1;
                    found=1;
                    ans.pb(mp(i,j));
                    break;
                }
            }
            if(!found){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES "<<diam<<endl;
    cout<<n-1<<endl;
    for(int i=0;i<n-1;i++){
        cout<<ans[i].f+1<<" "<<ans[i].s+1<<endl;
    }
}