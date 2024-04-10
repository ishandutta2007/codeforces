#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'

#define hash fsgfsd

const ll MOD = 11;
class hash{
public:
    ll h1,h2;
    hash(ll a = 0,ll b = 0){
        h1 = a;
        h2 = b;
    }
};
hash operator + (const hash &a,const hash &b){
    hash ret;
    ret.h1 = a.h1+b.h1;
    ret.h2 = a.h2+b.h2;
    if (ret.h2>=MOD)
        ret.h2-=MOD;
    return ret;
}
hash operator - (const hash &a,const hash &b){
    hash b1 = (-b.h1,MOD-b.h2);
    if (b1.h2==MOD)
        b1.h2 = 0;
    return a+b1;
}
hash operator *(const hash &a,const hash &b){
    hash ret = a;
    ret.h1*=b.h1;
    ret.h2 = (a.h2*b.h2)%MOD;
    return ret;
}
const bool operator == (const hash &a,const hash &b){
    return a.h1==b.h1 && a.h2==b.h2;
}
const bool operator != (const hash &a,const hash &b){
    return !(a==b);
}
const int N = 1e5+7;
const int base = 11;
hash T[N*4],po[N];
int mod[N*4];
int A[N];
hash merge(hash a,hash b,int shift){
    return a+(b*po[shift]);
}
void buildtree(int t,int tl,int tr){
    mod[t] = -1;
    if (tl==tr){
        T[t] = hash(A[tl],A[tl]);
        return;
    }
    int tm = (tl+tr)>>1;
    buildtree(t*2+1,tl,tm);
    buildtree(t*2+2,tm+1,tr);
    T[t] = merge(T[t*2+1],T[t*2+2],tm-tl+1);
}
hash H[base][N];
void push(int t,int tl,int tr){
    if (mod[t]==-1)
        return;
    mod[t*2+1] = mod[t*2+2] = mod[t];
    int tm = (tl+tr)>>1;
    T[t*2+1] = H[mod[t]][tm-tl+1];
    T[t*2+2] = H[mod[t]][tr-tm];
    mod[t] = -1;
}
hash query(int t,int tl,int tr,int l,int r){
    if (tl>r || l>tr)
        return hash(0,0);
    if (l<=tl && tr<=r)
        return T[t];
    push(t,tl,tr);
    int tm = (tl+tr)>>1;
    return merge(query(t*2+1,tl,tm,l,r),query(t*2+2,tm+1,tr,l,r),max(0,tm-max(l,tl)+1));
}
void update(int t,int tl,int tr,int l,int r,int sy){
    if (l>tr || tl>r)
        return;
    if (l<=tl && tr<=r){
        T[t] = H[sy][tr-tl+1];
        mod[t] = sy;
        return;
    }
    push(t,tl,tr);
    int tm = (tl+tr)>>1;
    update(t*2+1,tl,tm,l,r,sy);
    update(t*2+2,tm+1,tr,l,r,sy);
    T[t] = merge(T[t*2+1],T[t*2+2],tm-tl+1);
}
int n,m,k;
hash get(int l,int r){
    return query(0,1,n,l,r);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    po[0] = hash(1,1);
    for(int i = 1;i<N;++i){
        po[i].h1 = po[i-1].h1*base;
        po[i].h2 = (po[i-1].h2*base)%MOD;
    }
    for(int sy = 1;sy<base;++sy){
        for(int i = 1;i<N;++i){
            H[sy][i] = (H[sy][i-1]*po[1])+hash(sy,sy);
        }
    }

    cin>>n>>m>>k;
    for(int i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        A[i] = ch-'0'+1;
    }
    buildtree(0,1,n);
    while(m+k>0){
        --m;
        int type;
        cin>>type;
        if (type==1){
            int l,r,num;
            cin>>l>>r>>num;
            ++num;
            update(0,1,n,l,r,num);
        }
        else{
            int l,r,d;
            cin>>l>>r>>d;
            int flag = 0;
            if ((r-l+1)%d!=0){
                int left = (r-l+1)%d;
                if (get(l,l+left-1)!=get(r-left+1,r)){
                    flag = 1;
                }
                r-=left;
            }
            int cnt = (r-l+1)/d;
            while(cnt!=1){
                if (cnt%2!=0){
                    if (get(l,l+d-1)!=get(r-d+1,r)){
                        flag = 1;
                    }
                    r-=d;
                    --cnt;
                }
                int tm = cnt>>1;
                hash a = get(l,l+tm*d-1),b = get(l+tm*d,r);
                if (get(l,l+tm*d-1)!=get(l+tm*d,r))
                    flag = 1;
                r = l+tm*d-1;
                cnt = tm;
            }
            if (!flag)
                cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}