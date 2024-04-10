#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'

#define hash fsgfsd

const ll MOD = 1e9+123;
class hash{
public:
    int h1,h2;
    hash(ll a = 0,ll b = 0){
        h1 = a;
        h2 = b;
    }
};
hash operator + (const hash &a,const hash &b){
    hash ret;
    ret.h1 = a.h1+b.h1;

    return ret;
}
hash operator - (const hash &a,const hash &b){
    hash b1 = hash(-b.h1,MOD-b.h2);

    return a+b1;
}
hash operator *(const hash &a,const hash &b){
    hash ret = a;
    ret.h1*=b.h1;
    return ret;
}
const bool operator == (const hash &a,const hash &b){
    return a.h1==b.h1;
}
const bool operator != (const hash &a,const hash &b){
    return !(a==b);
}
const int base = 29;
const int N = 5000+7;
hash po[N],H[N];
hash get(int l,int r){
    return H[r]-(H[l-1]*po[r-l+1]);
}


int A[N],inter[N][N];
const int DIMOS = N*N;
pair<int,int> dp[DIMOS];
int comp(pair<int,int> a,pair<int,int> b,int flag = 0){
    if (flag==1){
        int len = min(a.second-a.first+1,b.second-b.first+1);
        if (get(a.first,a.first+len-1)==get(b.first,b.first+len-1)){
            return len+1;
        }

        int l = 1,r = len;
        while(l!=r){
            int tm = (l+r)>>1;
            if (get(a.first,a.first+tm-1)!=get(b.first,b.first+tm-1))
                r = tm;
            else l = tm+1;
        }
        return l;
    }
    int len = min(a.second-a.first+1,b.second-b.first+1);
    if (inter[a.first][b.first]>len)
        return (a.second-a.first)<(b.second-b.first);
    int l = inter[a.first][b.first];
    return A[a.first+l-1]<A[b.first+l-1];
}
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        A[i] = ch-'a'+1;
        H[i] = H[i-1]*po[1]+hash(A[i],A[i]);
    }
    for(int i = 1;i<=n;++i){
        inter[i][i] = n-i+1;
        for(int j = i-1;j>=1;--j){
            inter[j][i] = inter[i][j] = comp({i,n},{j,n},1);
        }
    }
    //if (n==5000)
    // return;
    int ptr = 0,last = 0;
    for(int i = 1;i<=n;++i){
        for(int j = i;j<=n;++j){
            if (ptr==0){
                ++ptr;
                dp[ptr] = {i,j};
                last = 1;
                continue;
            }
            int l = 1,r = ptr+1;
            if (i<j)
                l = last;
            while(l!=r){
                int tm = (l+r)>>1;
                if (comp(dp[tm],{i,j}))
                    l = tm+1;
                else r = tm;
            }
            last = l;
            if (l==ptr+1){
                ++ptr;
                dp[ptr] = {i,j};
            }
            else if (comp({i,j},dp[l]))
                dp[l] = {i,j};

        }
    }
    cout<<ptr<<endl;

}
int main() {
    po[0] = hash(1,1);
    for(int i = 1;i<N;++i){
        po[i].h1 = po[i-1].h1*base;
        po[i].h2 = (po[i-1].h2*base)%MOD;
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}