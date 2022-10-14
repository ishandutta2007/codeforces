#include <bits/stdc++.h>
using namespace std;
int N;
int a,b,w;
bool vis[1001];
bool pres[1001];
bool link[1001][1001];
vector <int> adj[1001];
void dele(int a, int b){
    if(b==a)return;
    pres[b]=1;
    vis[b]=1;
    for(auto x: adj[b]){
        if(!vis[x])dele(a,x);
    }
}
int main(){
    cin >> N;
    for(int i = 0; i < N-1; i++){
        cin >> a >> b;
        link[a][b]=1;
        link[b][a]=1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int k = 0;
    for(int i = 1;i <= N; i++)for(int j = i+1;j <= N; j++){
        if(pres[i])break;
        if(pres[j]||link[i][j])continue;
        cout <<"? "<< i<<" " << j<<endl;
        cin >> w; cout << endl;
        fflush(stdout);
        for(int q = 0;q <= N; q++)vis[q]=0;
        dele(w,i); dele(w,j);
    }
    for(int i = 1;i <= N; i++)for(int j = i+1;j <= N; j++){
        if(pres[i])break;
        if(pres[j])continue;
        cout <<"? "<< i<<" " << j<<endl;
        cin >> w; cout << endl;
        fflush(stdout);
        for(int q = 0;q <= N; q++)vis[q]=0;
        dele(w,i); dele(w,j);
    }
    for(int i = 1 ; i <= N; i++)if(!pres[i])cout <<"! "<< i<<"\n";
    return 0;
}