#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int edge[105][105];

vector <pair <int, int>> dist[105][105];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> edge[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(k == i || k == j) continue;
                dist[i][j].push_back({edge[i][k]+edge[k][j], k});
            }
            sort(dist[i][j].begin(), dist[i][j].end());
        }
    }
    int res = 1000000000;
    if(k == 2){
        for(int k1=1; k1<=1; k1++){
            int k2 = 1;
            int tr = 0; int ima = 0;
            for(auto c : dist[k1][k2]){
                if(c.second != k1){
                    tr += c.first; ima++;
                    break;
                }
            }
            if(ima >= 1) res = min(res, tr);
        }
    }
    else if(k == 4){
        for(int k1=1; k1<=1; k1++){
            for(int k2=1; k2<=n; k2++){
                int k3 = 1;
                int tr = 0; int ima = 0;
                for(auto c : dist[k1][k2]){
                    if(c.second != k1 && c.second != k2){
                        tr += c.first; ima++;
                        break;
                    }
                }
                for(auto c : dist[k2][k3]){
                    if(c.second != k1 && c.second != k2){
                        tr += c.first; ima++;
                        break;
                    }
                }
                if(ima >= 2) res = min(res, tr);
            }
        }
    }
    else if(k == 6){
        for(int k1=1; k1<=1; k1++){
            for(int k2=1; k2<=n; k2++){
                for(int k3=1; k3<=n; k3++){
                    int k4 = 1;
                    int tr = 0; int ima = 0;
                    for(auto c : dist[k1][k2]){
                        if(c.second != k1 && c.second != k2 && c.second != k3){
                            tr += c.first; ima++;
                            break;
                        }
                    }
                    for(auto c : dist[k2][k3]){
                        if(c.second != k1 && c.second != k2 && c.second != k3){
                            tr += c.first; ima++;
                            break;
                        }
                    }
                    for(auto c : dist[k3][k4]){
                        if(c.second != k1 && c.second != k2 && c.second != k3){
                            tr += c.first; ima++;
                            break;
                        }
                    }
                    if(ima >= 3) res = min(res, tr);
                }
            }
        }
    }
    else if(k == 8){
        for(int k1=1; k1<=1; k1++){
            for(int k2=1; k2<=n; k2++){
                for(int k3=1; k3<=n; k3++){
                    for(int k4=1; k4<=n; k4++){
                        int k5 = 1;
                        int tr = 0; int ima = 0;
                        for(auto c : dist[k1][k2]){
                            if(c.second != k1 && c.second != k2 && c.second != k3 && c.second != k4){
                                tr += c.first; ima++;
                                break;
                            }
                        }
                        for(auto c : dist[k2][k3]){
                            if(c.second != k1 && c.second != k2 && c.second != k3 && c.second != k4){
                                tr += c.first; ima++;
                                break;
                            }
                        }
                        for(auto c : dist[k3][k4]){
                            if(c.second != k1 && c.second != k2 && c.second != k3 && c.second != k4){
                                tr += c.first; ima++;
                                break;
                            }
                        }
                        for(auto c : dist[k4][k5]){
                            if(c.second != k1 && c.second != k2 && c.second != k3 && c.second != k4){
                                tr += c.first; ima++;
                                break;
                            }
                        }
                        if(ima >= 4) res = min(res, tr);
                    }
                }
            }
        }
    }
    else{
        for(int k1=1; k1<=1; k1++){
            for(int k2=1; k2<=n; k2++){
                for(int k3=1; k3<=n; k3++){
                    for(int k4=1; k4<=n; k4++){
                        for(int k5=1; k5<=n; k5++){
                            int k6 = 1;
                            int tr = 0; int ima = 0;
                            for(auto c : dist[k1][k2]){
                                if(c.second != k1 && c.second != k2 && c.second != k3 && c.second != k4 && c.second != k5){
                                    tr += c.first; ima++;
                                    break;
                                }
                            }
                            for(auto c : dist[k2][k3]){
                                if(c.second != k1 && c.second != k2 && c.second != k3 && c.second != k4 && c.second != k5){
                                    tr += c.first; ima++;
                                    break;
                                }
                            }
                            for(auto c : dist[k3][k4]){
                                if(c.second != k1 && c.second != k2 && c.second != k3 && c.second != k4 && c.second != k5){
                                    tr += c.first; ima++;
                                    break;
                                }
                            }
                            for(auto c : dist[k4][k5]){
                                if(c.second != k1 && c.second != k2 && c.second != k3 && c.second != k4 && c.second != k5){
                                    tr += c.first; ima++;
                                    break;
                                }
                            }
                            for(auto c : dist[k5][k6]){
                                if(c.second != k1 && c.second != k2 && c.second != k3 && c.second != k4 && c.second != k5){
                                    tr += c.first; ima++;
                                    break;
                                }
                            }
                            if(ima >= 5) res = min(res, tr);
                        }
                    }
                }
            }
        }
    }
    cout << res << "\n";
    return 0;
}