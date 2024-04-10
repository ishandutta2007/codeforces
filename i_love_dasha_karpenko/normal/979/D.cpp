//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e5+7;
const int LOG = 20;
int po[LOG+5];
struct tnode{
    int child[2] = {-1,-1};
} T[N*(LOG+5)];
int ptr = 0;
void add(int node,int num,int bit){
    if (bit<0)
        return;
    int cur = (num&po[bit])>>bit;
    if (T[node].child[cur]==-1)
        T[node].child[cur] = ++ptr;
    add(T[node].child[cur],num,bit-1);
}
int x,k,s;
int get(int node,int bit,int sum){
    if (sum+x>s)
        return -1;
    if (bit<0 && __gcd(sum,x)%k)
        return -1;
    else if (bit<0)
        return sum;
    int l = sum,r = sum+po[bit+1]-1;
    int frs = (l/k+(l%k!=0))*k;
    if (frs>r)
        return -1;
    int cur = (x&po[bit])>>bit;
    cur^=1;
    if (T[node].child[cur]!=-1){
        int ret = get(T[node].child[cur],bit-1,sum+po[bit]*cur);
        if (ret!=-1)
            return ret;
    }
    cur^=1;
    if (T[node].child[cur]!=-1){
        int ret = get(T[node].child[cur],bit-1,sum+po[bit]*cur);
        if (ret!=-1)
            return ret;
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    po[0] = 1;
    for(int i = 1;i<=LOG;++i)
        po[i] = po[i-1]*2;
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if (type==1){
            int x;
            cin>>x;
            add(0,x,LOG-1);
        }
        else{
            cin>>x>>k>>s;
            if (x%k)
                cout<<"-1\n";
            else
                cout<<get(0,LOG-1,0)<<endl;
        }
    }
    return 0;
}