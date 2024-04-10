#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &(x))
#define F first
#define S second
const int N = 1e5 + 10;
vector<pair< pair<int, int>, int> > constraints;
vector<pair<int, int> > vec;
int A[N];
int prefix[N], val[N];
int main(){
    int n, m; sd(n); sd(m);
    for(int i = 0; i < m; i++){
        int l, r, q;
        sd(l); sd(r); sd(q);
        constraints.push_back({{l, r}, q});
    }
    sort(constraints.begin(), constraints.end());
    for(int j = 0; j < 30; j++){
        memset(val, 0, sizeof val);
        vec.clear();
        int l = 1, r = 0;
        for(auto it : constraints){
            if(it.S & (1 << j)){
                int L = it.F.F, R = it.F.S;
                if(L > r){
                    for(int i = l; i <= r; i++) val[i] = 1, A[i] |= (1 << j);
                    l = L; r = R;
                }
                else{
                    r = max(R, r);
                }
            }
            else vec.push_back(it.F);
        }
        for(int i = l; i <= r; i++) val[i] = 1, A[i] |= (1 << j);
        for(int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + val[i];
        for(auto it : vec){
            if(prefix[it.S] - prefix[it.F - 1] == it.S - it.F + 1){
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES\n");
    for(int i  = 1; i <= n; i++) printf("%d ", A[i]);
}