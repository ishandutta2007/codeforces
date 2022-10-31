// Hydro submission #6235a1f0c3ac3ae453158f09@1647682032605
#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
using namespace std;

// inline __int128 read(){
//     int x=0,f=1;
//     char ch=getchar();
//     while(ch<'0'||ch>'9'){
//         if(ch=='-')
//             f=-1;
//         ch=getchar();
//     }
//     while(ch>='0'&&ch<='9'){
//         x=(x<<1)+(x<<3)+(ch^48);
//         ch=getchar();
//     }
//     return x*f;
// }
// inline void write(__int128 x){
//     if(x<0){
//         putchar('-');
//         x=-x;
//     }
//     if(x>9) write(x/10);
//     putchar(x%10+'0');
// }



namespace ls{
    const int maxnum = 5e5 + 5;
    int C[maxnum], L[maxnum], A[maxnum];

    void ls(int *f, int *a, int n){
        for(int i = 0; i < n; i++) A[i] = a[i+1];
        memcpy(C, A, sizeof(A));
        sort(C, C + n);
        int l = unique(C, C + n) - C;
        for(int i = 0; i < n; ++i){
            L[i] = lower_bound(C, C + l, A[i]) - C + 1;
            for(int i = 0; i < n; i++){
                f[i + 1] = L[i];
            }
        }
    }
}

typedef long long ll;
int pb, ps, pc;
int nb, ns, nc; 
int cnt1 = 0, cnt2 = 0, cnt3 = 0;
ll money;



bool check(ll x){
    ll cost = 0;
    cost = max((x * cnt1 - nb) * pb, 0LL) + max((x * cnt2 - ns) * ps, 0LL) + max((x * cnt3 - nc) * pc, 0LL);

    return cost <= money;
}




int head[2010], to[2010], nex[2010], tot = 0;
int dist[2010], vis[2010];
vector<int> path;
int a[100100];


void slove(){
    string s; 
    while(cin >> s){
        cnt1 = cnt2 = cnt3 = 0;
        for(auto c : s){
            if(c == 'B') cnt1++;
            else if(c == 'S') cnt2++;
            else cnt3++;
        }
        // cout << cnt1 <<  ' ' << cnt2 << ' ' << cnt3 << '\n'; 
        cin >> nb >> ns >> nc;
        cin >> pb >> ps >> pc;
        cin >> money;
        ll l = 0, r = money / (pb * cnt1 + ps * cnt2  + pc * cnt3 ) + 100;
        while(l < r){
            ll mid = (l + r + 1) >> 1;
            // cout << mid << '\n';
            if(check(mid)){
                l = mid;
            } else r = mid - 1;
        }
        cout << l << '\n';
    }

}





int main(){
    // ios::sync_with_stdio(0), cin.tie(0);
    slove();

}