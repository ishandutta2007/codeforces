#include <bits/stdc++.h>
using namespace std;

int s[1000],f[1000];
vector <int> graf[1000];
int color[1000];
int mark=0;

void dfs(int v){
    for(auto c : graf[v]){
        if(color[c]==color[v]){
            mark=1;
            return;
        }
        if(mark==1)return;
        if(color[c]==0){
            color[c]=3-color[v];
            dfs(c);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    int n,m,i,j;
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>s[i]>>f[i];
        if(f[i]<s[i])swap(f[i],s[i]);
    }
    for(i=0;i<m;i++){
        for(j=i+1;j<m;j++){
            if(s[i]<s[j] && f[i]>s[j] && f[i]<f[j]){
                graf[j].push_back(i);
                graf[i].push_back(j);
            }
            else if(s[j]<s[i] && f[j]>s[i] && f[j]<f[i]){
                graf[j].push_back(i);
                graf[i].push_back(j);
            }
        }
    }
    for(i=0;i<m;i++){
        if(color[i]==0){
            color[i]=1;
            dfs(i);
            if(mark==1){cout<<"Impossible";return 0;}
        }
    }
    for(i=0;i<m;i++){
        if(color[i]==1)cout<<'i';
        else cout<<'o';
    }
    return 0;
}