#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define gi(x) int(x-'a')
typedef long long ll;
const int N = 1e5+7;
const int AL = 26;
queue<int> V[AL];
int T[N];
int n;
void add(int pos,int delta){
    for(int i = pos;i<=n;i+=i&-i)
        T[i] += delta;
}
int get(int pos){
    int ret = 0;
    for(int i = pos;i>0;i-=i&-i)
        ret+=T[i];
    return ret;
}
char S[N];
void solve(){
    for(int i = 0;i<AL;++i)
        while(!V[i].empty())
            V[i].pop();
    for(int i = 0;i<=n;++i)
        T[i] = 0;

    cin>>n;
    for(int i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        V[gi(ch)].push(i);
    }
    for(int i = 1;i<=n;++i)
        cin>>S[i];
    ll res = ll(n)*n;
    ll cur = 0;
    bool flag = 0;
    for(int i = 1;i<=n;++i){

        int symb = gi(S[i]);
        for(int j = 0;j<symb;++j){
            if (V[j].empty())
                continue;
            int nxt = V[j].front();
            res = min(res,cur+(nxt+get(nxt)-i));
            flag = 1;
        }
        if (V[symb].empty()){
            break;
        }
        int nxt = V[symb].front();
        V[symb].pop();
        cur+=(nxt+get(nxt)-i);
        add(1,1);
        add(nxt,-1);
    }
    if (!flag)
        cout<<"-1\n";

    else
        cout<<res<<endl;

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}