#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MAXN 1000010

// FENWICK

int fenwick[MAXN];
void update(int pos, int delta){
    for(;pos < MAXN; pos+=pos&-pos)fenwick[pos]+=delta;
}
int query(int pos){
    int res = 0;
    for(; pos>0; pos-=pos&-pos)res+=fenwick[pos];
    return res;
}
int T;
int N,Q,a;



int main(){
    cin >> N >> Q;

    for(int i = 0; i < N;i++){
        scanf("%d",&a);
        update(a,1);
    }
    int ub, lb,mid;
    while(Q--){
        scanf("%d",&a);
        if(a > 0){update(a,1); continue;}
        a = -a;
        ub = N; lb = 0;
        while(ub >= lb){
            mid = (ub+lb)/2;
            if(query(mid)>=a)ub = mid -1;
            else lb = mid +1;
        }
        update(ub +1, -1);
    }
    if(query(1000000) == 0)cout << 0;
    else{
    ub = N; lb = 0;
    while(ub >= lb){
        mid = (ub+lb)/2;
        if(query(mid)>=1)ub = mid -1;
        else lb = mid +1;
    }
    cout << ub +1;
    }
    return 0;
}