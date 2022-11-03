#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

const int N=1e5+10;

int n;
vector <int> v[N];


int q[N],h[N];
int BFS(int st){
        h[st]=1;
        q[1]=st;
        int top=1,bot=1;
        while (top<=bot){
                int x=q[top++];
                for(auto y:v[x]) if (!h[y]){
                        h[y]=1;
                        q[++bot]=y;
                }
        }
        return q[bot];
}
void solve(){
        int ldeg=0;
        for(int i=1;i<=n;i++) if (v[i].size()>=3) ldeg++;
        if (ldeg>=2){
                cout<<"No";
                return;
        }
        cout<<"Yes\n";
        if (ldeg==0){
                cout<<"1\n";
                for(int i=0,cur=1;i<=1;i++){
                        while (v[cur].size()!=1) cur++;
                        cout<<cur<<" ";
                        cur++;
                }
                return;
        }
        int root=1;
        while (v[root].size()<=2) root++;
        h[root]=1;
        cout<<v[root].size()<<'\n';
        for(auto y:v[root]) cout<<root<<" "<<BFS(y)<<'\n'; 
}
int main(){
        cin>>n;
        for(int i=1;i<n;i++){
                int x,y;
                cin>>x>>y;
                v[x].push_back(y);
                v[y].push_back(x);
        }

        solve();
}