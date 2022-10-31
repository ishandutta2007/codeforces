// Hydro submission #6235984836b6cce26b323c8c@1647679561031
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

bool cmp(pair<int,int> a, pair<int, int> b){
    return a.first >= b.first;
}

typedef long long ll;

int head[2010], to[2010], nex[2010], tot = 0;
int dist[2010], vis[2010];
vector<int> path;
int a[100100];
pair<int, int> arr[100100];
int ans[100100];

void slove(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    int cnt = 0;
    for(int i = n; i >= 1; i--){
       // cout << i << '\n';
        if(i == n) {
            arr[++cnt] = {a[i], i};
            ans[i] = -1;
        }else {
            if(a[i] <= arr[cnt].first){
                arr[++cnt] = {a[i], i};
                ans[i] = -1;
            }
            else {
                // for(int i = 1;  i <= cnt; i++) {
                //     cout << arr[i].first << ' ' << arr[i].second << '\n';
                // }
                ans[i] = abs(i - lower_bound(arr + 1, arr + cnt + 1, make_pair(a[i], INF), cmp)->second + 1);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';

}





int main(){
    // ios::sync_with_stdio(0), cin.tie(0);
    slove();

}