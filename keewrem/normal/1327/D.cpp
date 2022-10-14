#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

bool vis[200010];
vector<vector<int>> cycles;
int T,N,q;
vector<int> viv;
int col[200010], perm[200010];
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        cycles.clear();
        for(int i = 0; i <=N;i++)vis[i]=0;
        for(int i = 1; i<=N; i++)cin >> perm[i];
        for(int i = 1; i<= N; i++) cin >> col[i];
        for(int i = 1; i <= N; i++){
            if(!vis[i]){
                viv.clear();
                viv.push_back(i);
                vis[i]=1;
                q = perm[i];
                while(q!=i){
                    vis[q]=1;
                    viv.push_back(q);
                    q = perm[q];
                }
                cycles.push_back(viv);
            }
        }
        //cout << "saaas";
        int s;
        bool sas;
        int ans = N+1;
        for(auto x: cycles){
            s = (int)x.size();
            ans = min(ans,s);
            for(int i = 1; i < s; i++){
                if(s%i!=0)continue;
                for(int j = 0; j < i; j++){
                    sas = 1;
                    for(int l = j+i; l < s; l+=i){
                        if(col[x[l]]!=col[x[l-i]])sas=0;
                    }
                    if(sas)ans = min(i,ans);
                }
            }
        }
        /*for(auto x: cycles){
            cout << "v ";
            for(auto y : x)cout << y << " ";
            cout <<"\n";
        }*/
        cout << ans << "\n";
    }
    return 0;
}