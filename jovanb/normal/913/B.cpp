#include <bits/stdc++.h>
using namespace std;

bool leaf[10000];
//vector <long long> graf[10000];
long br[10000];

/*void dfs(long v){
    br[v]++;
    for (auto c : graf[v]){
        dfs(c);
    }
    return;
}*/
pair <long,long> par[10000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    long n,x,i;
    cin>>n;
    for(i=1;i<=n;i++)leaf[i]=true;
    leaf[1]=false;
    for(i=2;i<=n;i++){
        cin>>x;
        //graf[i].push_back(x);
        leaf[x]=false;
        //br[x]++;
        par[i].first=i;
        par[i].second=x;
    }

    /*for(i=1;i<=n;i++){
        if(leaf[i]==true){
            dfs(i);

        }
    }*/
    for(i=2;i<=n;i++){
        if(leaf[par[i].first]==true){
            br[par[i].second]++;
        }
    }
    for(i=1;i<=n;i++){
        if(leaf[i]==false){
            if(br[i]<3){cout<<"No";return 0;}
        }
    }
    cout<<"Yes";
    return 0;
}