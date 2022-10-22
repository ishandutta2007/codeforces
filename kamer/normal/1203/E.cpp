#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
    int n;
    std::cin >> n;
    std::vector<int> weights(n);
    std::vector<bool> seen(150000 + 2, false);
    for (int i = 0; i < n; i++)
        std::cin >> weights[i];
        
    std::sort(weights.begin(), weights.end());
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        int w = weights[i];
        for (int j = w - 1; j <= w + 1; j++) {
            if (j > 0 && !seen[j]) {
                count++;
                seen[j] = true;
                break;
            }
        }
    }
    
    std::cout << count;
    return 0;
}