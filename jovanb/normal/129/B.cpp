#include <bits/stdc++.h>
using namespace std;

long elim[1000];
vector <long> graf[1000];
queue <long> q;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long n,br=0,m,i,v,a,b;
    unsigned long x;
    cin>>n>>m;
    for(i=0; i<m; i++){
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    while(1){
        for(i=1; i<=n; i++){
            if(elim[i]==0){
                if(graf[i].size()==1){
                    elim[i]=1;
                    q.push(i);
                }
            }
        }
        if(q.empty()){cout<<br;return 0;}
        while(!q.empty()){
            i=q.front();
            v=graf[i][0];
            for(x=0; x<graf[v].size(); x++){
                if(graf[v][x]==i){
                    graf[v].erase(graf[v].begin()+x);
                }
            }
            q.pop();
        }
        br++;
    }
    cout<<br;
    return 0;
}