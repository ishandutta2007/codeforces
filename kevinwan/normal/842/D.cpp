#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=1e6+10;
struct nd{
    nd *c[2];
    bool gud=0;
};
nd*trie;
inline int gud(nd*n){return n?n->gud:0;}
void add(nd*&n,int p,int x){
    if(p==-1){
        n->gud=1;
    }
    else{
        bool t=(x>>p)&1;
        if(!(n->c[t]))n->c[t]=new nd();
        add(n->c[t],p-1,x);
        n->gud=gud(n->c[0])&&gud(n->c[1]);
    }
}
int fin(nd*&n,int p,int x){
    if(!n)return 0;
    if(p==-1)return 0;
    bool t=(x>>p)&1;
    if(!(n->c[t]))return 0;
    if(gud(n->c[t]))return (1<<p)+fin(n->c[!t],p-1,x);
    else return fin(n->c[t],p-1,x);
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m,i;
    cin>>n>>m;
    trie=new nd();
    for(i=0;i<n;i++){
        int x;
        cin>>x;
        add(trie,18,x);
    }
    int cum=0;
    while(m--){
        int x;
        cin>>x;
        cum^=x;
        printf("%d\n",fin(trie,18,cum));
    }
}