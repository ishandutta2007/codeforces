            #include <iostream>
            #include <vector>
             
            int main(void) {
                std::ios_base::sync_with_stdio(false);
                std::cin.tie(0);
                int n, x, y;
                std::cin >> n >> x >> y;
                std::vector<int> rains(n);
                for (int i = 0; i < n; i++)
                    std::cin >> rains[i];
                    
                for (int i = 0; i < n; i++) {
                    bool best = true;
                    for (int j = -x; j <= y; j++) {
                        if (i + j >= 0 && i + j < n && j != 0)
                            if (rains[i + j] <= rains[i]) {
                                best = false;
                                break;
                            }
                    }
                    if (best) {
                    std::cout << i + 1;
                    return 0;
                    }
                }
            }