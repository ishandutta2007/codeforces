#include<bits/stdc++.h>
using namespace std;

const int SQRT = 333;
const int maxn = 2e5 , maxx = 2e6;

struct query{
    int l,r,ind;
}Q[maxn];

int a[maxn],n,q,k , t[maxx];
long long cnt, ans[maxn];

bool cmp(query A, query B) {
    if(A.l/SQRT != B.l/SQRT)
        return A.l<B.l;
    return A.r<B.r;
}

void add(int x)
{
    cnt += t[x^k];
    t[x] ++;
}

void del(int x)
{
    t[x] --;
    cnt -= t[x^k];
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>q>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i) a[i]^=a[i-1];
    }
    for(int i=0;i<q;i++){
        cin>>Q[i].l>>Q[i].r;
        Q[i].l--;
        Q[i].r++;
        Q[i].ind = i;
    }
    sort(Q,Q+q,cmp);
    int L=0,R=0;
    for(int i=0;i<q;i++)
    {
        while(Q[i].l<L)
        {
            L--;
            add(a[L]);
        }
        while(Q[i].r>R)
        {
            add(a[R]);
            R++;
        }
        while(Q[i].l>L)
        {
            del(a[L]);
            L++;
        }
        while(Q[i].r<R)
        {
            R--;
            del(a[R]);
        }
        ans[Q[i].ind] = cnt;
    }
    for(int i=0;i<q;i++)
        cout<<ans[i]<<'\n';
}