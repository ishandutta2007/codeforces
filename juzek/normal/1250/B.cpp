#include <iostream>

int main() {
    int n, miski, talerze, x, wyn = 0;
    scanf("%d%d%d", &n, &miski, &talerze);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (x == 1) {
            miski--;
            if (miski < 0) {
                wyn++;
            }
        } else {
            if (talerze > 0)
                talerze--;
            else {
                miski--;
                if (miski < 0) {
                    wyn++;
                }
            }
        }
    }
    printf("%d", wyn);
    return 0;
}