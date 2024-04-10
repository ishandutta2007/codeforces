#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

typedef pair<int, int> P;
bool ok(const vector<int>& a, const vector<int>& b, const vector<int>& c, int k, int S, vector<int>& answer){
    int N = a.size();
    int M = b.size();
    priority_queue<P, vector<P>, greater<P>> que;
    vector<int> cnt(M, 0);
    long long sum = 0;
    for(int i = 0, j = 0; i < N; i++){
        while(j < M && b[j] >= a[i]){
            que.push(P(c[j], j));
            j++;
        }
        if(que.empty()) return false;
        int l = que.top().second;
        cnt[l]++;
        sum += que.top().first;
        answer[i] = l;

        if(cnt[l] == 1){
            que.pop();
            if(cnt[l] < k) que.push(P(0, l));
        } else if(cnt[l] == k){
            que.pop();
        }
    }
    return sum <= S;
}

int main(){
    int N, M, S;
    while(cin >> M >> N >> S){
        vector<P> pva(N);
        vector<P> pvb(M);
        vector<int> cc(M);
        REP(i, N) cin >> pva[i].first;
        REP(i, M) cin >> pvb[i].first;
        REP(i, M) cin >> cc[i];

        REP(i, N) pva[i].second = i;
        REP(i, M) pvb[i].second = i;

        sort(pva.begin(), pva.end());
        sort(pvb.begin(), pvb.end());
        reverse(pva.begin(), pva.end());
        reverse(pvb.begin(), pvb.end());

        vector<int> a(N), b(M), c(M);
        REP(i, N) a[i] = pva[i].first;
        REP(i, M) b[i] = pvb[i].first;
        REP(i, M) c[i] = cc[pvb[i].second];

        //REP(i, N) cout << a[i] << " "; cout << endl;
        //REP(i, M) cout << b[i] << " "; cout << endl;
        //REP(i, M) cout << c[i] << " "; cout << endl;

        int lb = 0, ub = N;
        vector<int> answer(N);
        while(ub - lb > 1){
            int x = (lb + ub) / 2;
            if(ok(a, b, c, x, S, answer)){
                ub = x;
            }else{
                lb = x;
            }
        }
        if(ok(a, b, c, ub, S, answer)){
            cout << "YES" << endl;
            vector<int> answer2(N);
            REP(i, N) answer2[ pva[i].second ] = answer[i];
            REP(i, N) {
                cout << pvb[ answer2[i] ].second + 1;
                if(i == N - 1) cout << endl;
                else cout << " ";
            }
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}