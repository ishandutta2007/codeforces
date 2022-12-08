#include <bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define f first
#define s second
#define pb push_back
#define MAXN 212345
#define pii pair<int,int>
#define pdd pair<double,double>
#define one 1
#define int long long
#define mp make_pair
#define ld long double

int n;
int bits[1123];
int val[112345];
vector<int> are[112345];
int dis[112345];
int fsc(int i){
    for(int j=0;j<n;j++)dis[j]=-1;
    dis[i]=0;
    //cara,pai
    queue<pii> q;
    q.push(mp(i,i));
    //cout<<i<<endl;
    while(q.size()>0){
        pii at=q.front();
        q.pop();
        //cout<<at.f<<" "<<at.s<<" "<<dis[at.f]<<endl;
        for(int x:are[at.f]){
            //cout<<"visita "<<x<<endl;
            if(dis[x]!=-1 && x!=at.s){
                //cout<<x<<endl;
                return dis[at.f]+dis[x]+1;
            }
            if(dis[x]==-1){
                dis[x]=dis[at.f]+1;
                q.push(mp(x,at.f));
            }
        }
    }
    return -1;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(2);
    cout.setf(ios::fixed);

    cin>>n;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        val[i]=x;
        for(int j=0;j<64;j++){
            bits[j]+=(x>>j)%2;
        }
    }
    for(int i=0;i<64;i++){
        //cout<<bits[i]<<" ";
        if(bits[i]>2){
            cout<<3<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        if(val[i]==0)continue;
        for(int j=i+1;j<n;j++){
            if(val[j]==0)continue;
            if((val[i]&val[j])!=0){
                are[i].pb(j);
                are[j].pb(i);
            }
        }
    }

    int resp=-1;
    for(int i=0;i<n;i++){
        if(val[i]==0)continue;
        int x=fsc(i);
        if(x!=-1){
            if(resp==-1)resp=x;
            else resp=min(resp,x);
        }
    }
    cout<<resp<<endl;



    return 0;
}