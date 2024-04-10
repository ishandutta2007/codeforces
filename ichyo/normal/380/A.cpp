#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef long long LL;

int main(){
    int M;
    const LL L = 100010;
    while(cin >> M){
        vector<int> type(M);
        vector<LL> l(M), c(M);
        REP(i, M){
            cin >> type[i];
            if(type[i] == 1){
                cin >> l[i];
            }else{
                cin >> l[i] >> c[i];
            }
        }
        int N;
        cin >> N;
        vector<LL> index(N + 1, LLONG_MAX);
        vector<int> answer(N + 1);
        REP(i, N) cin >> index[i];
        REP(i, N) index[i] --;
        vector<int> have;
        LL curr = 0;
        int k = 0;

        REP(i, M){
            if(type[i] == 1){
                // update answer
                if(index[k] == curr){
                    answer[k++] = l[i];
                }

                // update have
                if(curr < L){
                    have.push_back(l[i]);
                }

                // update curr
                curr++;
            }else{
                LL next = curr + l[i] * c[i];
                // update answer
                while(index[k] < next){
                    answer[k] = have[ (index[k] - curr) % l[i] ];
                    k++;
                }
                // update have
                LL j = curr;
                while(j < L && j < next){
                    have.push_back( have[ (j - curr) % l[i] ] );
                    j++;
                }
                // update curr
                curr = next;
            }
        }

        REP(i, N){
            cout << answer[i];
            if(i == N - 1) cout << endl;
            else cout << " ";
        }

    }
    return 0;
}