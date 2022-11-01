//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 5E3+7;
const int AL = 26;
int k,n,vis[N],F[AL];
string A[N];
void solve(vector<int> &V,int pos){
    if (V.size()>4){
        cout<<"-1\n";
        exit(0);
    }
    do{
        string base = A[1];

        for(int i = 0;i<k;++i){
            if (vis[i]==0)
                base[i] = A[pos][i];
            else base[i] = A[pos][V[vis[i]-1]];

        }

        int flag = 0;
        for(int i = 1;i<=n;++i){
            int ps = -1,cnt = 0;
            memset(F,0,sizeof(F));
            for(int j = 0;j<k;++j){
                if (A[i][j]!=base[j])
                    ++cnt;
                ++F[int(A[i][j]-'a')];
            }
            if (cnt>2){
                flag = 1;
                break;
            }
            for(int j = 0;j<k;++j){
                if (A[i][j]!=base[j]){
                    if (ps==-1)
                        ps = j;
                    else{
                        if (A[i][j]!=base[ps] && A[i][ps]!=base[j])
                            flag = 1;
                        break;
                    }
                }
            }
            if (cnt==0){
                flag = 1;
                for(int j = 0;j<AL;++j)
                    if (F[j]>1)
                        flag = 0;
            }
            if (flag)
                break;
        }
        if (!flag){

            cout<<base<<'\n';
            exit(0);
        }
    }while(next_permutation(V.begin(),V.end()));
}
void solve(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>>n>>k;
    for(int ps = 1;ps<=n;++ps){
        cin>>A[ps];
    }
    int flag = 0;
    for(int ps = 2;ps<=n;++ps){
        if (A[ps]==A[1])
            continue;
        vector<int> V;
        int ptr = 0;
        flag = 1;
        for(int i = 0;i<k;++i){
            vis[i] = 0;
            if (A[ps][i]!=A[1][i])
                V.push_back(i),vis[i] = ++ptr;
        }
        solve(V,ps);
    }
    if (flag){
        cout<<"-1\n";
        return;
    }
    swap(A[1][0],A[1][1]);
    cout<<A[1]<<'\n';
}
// 6: xxx xxx
int main()
{

    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}