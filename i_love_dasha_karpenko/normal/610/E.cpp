//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int K = 10+2;
const int N = 2e5+7;
int cnt[K][K];
int gi(char ch){
    return ch-'a';
}
struct node{
    int pos,symb,len;
};
const bool operator < (const node &a,const node &b){
    return a.pos<b.pos;
}
void split(set<node> &S,int pos){
    auto it = prev(S.upper_bound({pos,0,0}));
    node val = *it;
    if (val.pos>=pos || pos-val.pos>=val.len)
        return;
    S.erase(it);
    node tl = {val.pos,val.symb,pos-val.pos};
    node tr = {pos,val.symb,val.len-tl.len};
    S.insert(tl);
    S.insert(tr);
}
void rem_next(set<node> &S,_Rb_tree_const_iterator<node> it,int delta){
    if (next(it)==S.end())
        return;
    cnt[it->symb][next(it)->symb]+=delta;
}
void rem(_Rb_tree_const_iterator<node> it){
    cnt[it->symb][it->symb]-=it->len-1;
}
void del(set<node> &S,int l,int r){
    auto it = S.lower_bound({l,0,0});
    if (it!=S.begin())
        rem_next(S,prev(it),-1);
    while(it!=S.end() && it->pos<=r){
        rem_next(S,it,-1);
        rem(it);
        it = next(it);
        S.erase(prev(it));
    }
}
void add(set<node> &S,int l,int r,int symb){
    node cur = {l,symb,r-l+1};
    cnt[symb][symb]+=r-l;
    auto it = S.insert(cur).first;
    if (it!=S.begin())
        rem_next(S,prev(it),1);
    rem_next(S,it,1);
}
int place[K];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int prv = -1,len = 0;
    set<node> S;
    for(int i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        int cur = gi(ch);
        if (cur==prv){
            ++len;
        }
        else{
            if (len)
                S.insert(S.end(),{i-len,prv,len});
            len = 1;
        }
        if (prv!=-1)
            cnt[prv][cur]++;
        prv = cur;
    }
    if (len)
        S.insert(S.end(),{n+1-len,prv,len});
    for(int q = 1;q<=m;++q){
        int type;
        cin>>type;
        if (type==1){
            int l,r;
            char ch;
            cin>>l>>r>>ch;
            split(S,l);
            split(S,r+1);
            int cur = gi(ch);
            del(S,l,r);
            add(S,l,r,cur);
        }
        else{
            for(int i = 1;i<=k;++i){
                char ch;
                cin>>ch;
                place[i] = gi(ch);
            }
            int res = 1;
            for(int i = 1;i<=k;++i){
                for(int j = i;j>=1;--j){
                    res+=cnt[place[i]][place[j]];
                }
            }
            cout<<res<<endl;
        }
    }
    return 0;
}