#include<bits/stdc++.h>
using namespace std;
int T,n,a[210000],b[210000];
int deg[210000],tot[210000];
vector<int> vec[210000];
queue<int> que;
bool topo_sort(){
    for (int i=1;i<=n;i++)
        if (!deg[i]) que.push(i);
    while (!que.empty()){
        int u=que.front(); que.pop();
        for (int v:vec[u]){
            deg[v]--;
            if (!deg[v]) que.push(v);
        }
    }
    for (int i=1;i<=n;i++)
        if (deg[i]) return false;
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>T;
    while (T--){
        cin>>n; int num=1;
        for (int i=1;i<=n;i++){
            cin>>a[i]; tot[a[i]]++;
            if (tot[a[i]]>=tot[num]) num=a[i];
        }
        for (int i=1;i<=n;i++) cin>>b[i];

        for (int i=1;i<=n;i++)
            if (a[i]!=num&&b[i]!=num) vec[a[i]].push_back(b[i]),deg[b[i]]++;
        
        if (topo_sort()) cout<<"AC\n";
        else cout<<"WA\n";
        for (int i=1;i<=n;i++) tot[i]=0,vec[i].clear(),deg[i]=0;
    }
    return 0;
}