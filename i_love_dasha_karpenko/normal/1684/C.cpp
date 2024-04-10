#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int NM = 2e5+7;
int A[NM];
bool vis[NM];
bool fvis[NM];
bool Check(int i,int j,int m){
    bool ret = 1;
    if (j>0 && A[i*m+j]<A[i*m+j-1]){
        ret = 0;
    }
    if (j+1<m && A[i*m+j]>A[i*m+j+1]){
        ret = 0;
    }
    return ret;
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i+=1){
        fvis[i] = 0;
    }
    for(int i = 0;i<n;i+=1){
        for(int j = 0;j<m;j+=1){
            cin>>A[i*m+j];

        }
    }
    for(int i = 0;i<n;i+=1){
        for(int j = 0;j<m;j+=1){
            if ((j>0 && A[i*m+j]<A[i*m+j-1]) || (j+1<m && A[i*m+j]>A[i*m+j+1])){
                fvis[j] = 1;
            }
        }
    }
    vector<int> V;
    for(int i = 0;i<m;i+=1){
        if (fvis[i]){
            V.push_back(i);
        }
    }
    if (V.size()>10){
        cout<<"-1\n";
        return;
    }
    if (V.size()==0){
        cout<<"1 1\n";
        return;
    }
    for(auto fpos:V) {
        for (int i = 0; i < m; i += 1) {
            vis[i] = 1;
        }
        for (int i = 0; i < n; i += 1) {
            int bad = 0;
            for(int j = 0;j<m;j+=1){
                bad += !Check(i,j,m);
            }
            for (int j = 0; j < m; j += 1) {
                set<int> S;
                for(int d = -1;d<=1;d+=1){
                    S.insert(min(m-1,max(0,j+d)));
                    S.insert(min(m-1,max(0,fpos+d)));
                }
                int delta = 0;
                for(int to:S){
                    delta += !Check(i,to,m);
                }
                swap(A[i * m + j], A[i * m + fpos]);
                for(int to:S){
                    delta -= !Check(i,to,m);
                }
                if (delta!=bad){
                    vis[j] = 0;
                }
                swap(A[i * m + j], A[i * m + fpos]);
            }
        }
        for(int i = 0;i<m;i+=1){
            if (vis[i]){
                cout<<fpos+1<<' '<<i+1<<endl;
                return;
            }
        }
    }
    cout<<"-1\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}