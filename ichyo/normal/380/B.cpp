#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
struct Query{
    int t, l, r, x;
};

bool in_range(int x, int l, int r){
    return l <= x && x <= r;
}

int f(int x){
    for(int i = 29; i >= 0; i--){
        if((1 << i) & x){
            if(x == (1 << i)) return x + i;
            else              return x + i + 1;
        }
    }
    return 1;
}
int g(int x){
    for(int i = 29; i >= 0; i--){
        if((1 << i) & x){
            return x + i + 1;
        }
    }
    return 1;
}

int main(){
    int N, M;
    while(cin >> N >> M){
        N += 1;
        vector<Query> query;
        REP(i, M){
            int type;
            cin >> type;
            if(type == 1){
                Query q;
                cin >> q.t >> q.l >> q.r >> q.x;
                query.push_back(q);
            }else if(type == 2){
                vector<int> left(N);
                vector<int> right(N);
                int t, v;
                cin >> t >> v;
                left[t] = v;
                right[t] = v;
                for(int i = t; i + 1 < N; i++){
                    left[i + 1] = f(left[i]);
                    right[i + 1] = g(right[i]);
                    //printf("left[%d] = %d\n", i + 1, left[i + 1]);
                    //printf("right[%d] = %d\n", i + 1, right[i + 1]);
                }

                set<int> ans;
                for(Query q : query){
                    if(q.t >= t && (in_range(left[q.t], q.l, q.r) || in_range(right[q.t], q.l, q.r) 
                                    || in_range(q.l, left[q.t], right[q.t]) || in_range(q.r, left[q.t], right[q.t]))){
                        ans.insert(q.x);
                    }
                }
                cout << ans.size() << endl;
            }
        }
    }
    return 0;
}