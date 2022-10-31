#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int CL = 3;
const int INF = 1e9+123;
vector<pair<int,int> > V[4][CL];


bool checkrow(vector<int> perm,int need,int ind){
    int rx = -INF;
    bool flag = false;

    for(int col:perm){
        ++rx;

        int cnt = 0;
        for(auto [x,y]:V[ind][col]){
            if (x>=rx)
                ++cnt;
            rx = max(x,rx);
            if (cnt==need)
                break;
        }
        if (cnt!=need)
            return false;
    }
    return true;

}
bool check1(vector<int> perm,int need){
    // check x
    bool ans = false;
    for(int u = 0;u<2;++u){
        ans = max(ans,checkrow(perm,need,u));
    }
    return ans;
}
bool mc(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}
bool checkT(vector<int> perm,int need,int ind){
    int rx = -INF;
    int cnt = 0;
    for(auto [x,y]:V[ind][perm[0]]){
        rx = max(rx,x);
        ++cnt;
        if (cnt==need)
            break;
    }
    if (cnt!=need)
        return false;
    ++rx;

    int ry = -INF;
    for(int j = 1;j<CL;++j){
        int col = perm[j];
        ++ry;
        int cnt = 0;
        for(auto [y,x]:V[(ind&1)^1][col]){
            int sign = (ind&2)?-1:1;
            if (x*sign<rx || y<ry)
                continue;
            ry = max(ry,y);
            ++cnt;
            if (cnt==need)
                break;
        }
        if (cnt!=need)
            return false;
    }
    return true;
}
bool check2(vector<int> perm,int need){
    bool ans = false;
    for(int u = 0;u<2;++u){
        for(int u1 = 0;u1<2;++u1){
            ans = max(ans,checkT(perm,need,u+u1*2));
        }
    }
    return ans;
}
bool F(int need){
    vector<int> perm(CL);
    for(int i = 0;i<CL;++i)
        perm[i] = i;
    do{
        if (check1(perm,need))
            return true;
        if (check2(perm,need))
            return true;
    }while(next_permutation(all(perm)));
    return false;
}
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        int x,y,c;
        cin>>x>>y>>c;
        c--;
        V[0][c].push_back({x,y});
    }
    for(int c = 0;c<CL;++c){
        V[1][c] = V[0][c];
        V[2][c] = V[0][c];
        V[3][c] = V[0][c];
        int sz = V[0][c].size();
        for(int j = 0;j<sz;++j)
            swap(V[1][c][j].first,V[1][c][j].second),swap(V[3][c][j].first,V[3][c][j].second);
        for(int j = 0;j<sz;++j)
            V[2][c][j].first*=-1,V[3][c][j].first*=-1;
        for(int cl = 0;cl<4;++cl)
            sort(all(V[cl][c]));

    }
    //sort(all(V[0]));

    int l = 0,r = n/3;
    while(l!=r){
        int mid = (l+r+1)>>1;
        if (F(mid))
            l = mid;
        else r = mid-1;
    }
    //cout<<F(3)<<endl;
    cout<<l*3<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    while(t--)
        solve();
    return 0;
}