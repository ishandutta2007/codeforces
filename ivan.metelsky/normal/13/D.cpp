#include <iostream>
#include <vector>
using namespace std;

class TheMoviesLevelOneDivOne {
public:
    long long find(int n, int m, vector<int> row, vector<int> seat) {
        return 0;
    }
    
    void doJob() {
        int N, M;
        cin >> N >> M;
        long long rx[512], ry[512], bx[512], by[512];
        for (int i=0; i<N; i++) cin >> rx[i] >> ry[i];
        for (int i=0; i<M; i++) cin >> bx[i] >> by[i];
        int sz=16;
        int mask[512][512][16];
        long long precalcRR[512][512];
        long long precalcBR[512][512];
        for (int i=0; i<N; i++)
            for (int j=i+1; j<N; j++) {
                precalcRR[i][j] = (rx[j]-rx[i])*(ry[i]+ry[j]);
            }
        for (int j=0; j<N; j++)
            for (int k=0; k<M; k++) {
                precalcBR[j][k] = (bx[k]-rx[j])*(ry[j]+by[k]);
            }
        for (int i=0; i < N; i++)
            for (int j=i+1; j < N; j++)
                    for (int k=0; k < M; k++)
                        if (precalcRR[i][j] + precalcBR[j][k] - precalcBR[i][k] > 0)
                            {                           
                            mask[i][j][k>>5] |= (1l << (k & 31));
                        } else mask[j][i][k>>5] |= (1l << (k & 31));
        int res = 0;
        
        int* a, b, c;
        
        for (int i=0; i < N; i++)
            for (int j=i+1; j < N; j++) {
                for (int k=j+1; k < N; k++) {
                    bool find = false;
                    if (/*right_triple(rx[i], ry[i], rx[j], ry[j], rx[k], ry[k])*/
                        /*(rx[j]-rx[i])*(ry[i]+ry[j]) + (rx[k]-rx[j])*(ry[j]+ry[k]) + (rx[i]-rx[k])*(ry[i]+ry[k]) > 0) */
                        precalcRR[i][j] + precalcRR[j][k] - precalcRR[i][k] > 0) {
                        //a = mask[i][j]; b = mask[j][k]; c = mask[k][i];
                        for (int t=0; t<sz; t++)
                            if ((mask[i][j][t] & mask[j][k][t] & mask[k][i][t]) != 0) {
                                find = true;
                                break;
                            }
                    } else {
                        //a = mask[i][k]; b = mask[k][j]; c = mask[j][i];
                        for (int t=0; t<sz; t++)
                            if ((mask[i][k][t] & mask[k][j][t] & mask[j][i][t]) != 0) {
                                find = true;
                                break;
                            }
                    }
                    if (!find) res++;
                }
            }
        
        cout << res;
    }
};

int main() {
    TheMoviesLevelOneDivOne obj;
    obj.doJob();
}