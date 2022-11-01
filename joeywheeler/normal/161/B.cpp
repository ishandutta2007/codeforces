#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct item {
    int val, id, type;
};

double total;
item price[1010];
int idPrice[1010];
int num, numC, numS, numP, remC, temp;
item stools[1010];
int whichCart[1010];
int minCart[1010];
vector <int> carts[1010];

bool itemSort (item a, item b) {
    return a.val > b.val;
}

int main() {
    //freopen ("test.in", "r", stdin);
    //freopen ("test.out", "w", stdout);
    scanf ("%d %d", &num, &numC);
    for(int i = 0; i < num; i++) {
        scanf ("%d", &price[i].val);
        scanf ("%d", &temp);
        idPrice[i+1] = price[i].val;
        total += price[i].val;
        price[i].type = temp;
        price[i].id = i + 1;
        if (temp == 1) {
            stools[numS].val = price[i].val;
            stools[numS].id = i + 1;
            stools[numS++].type = 1;
        }
    }
    sort (price, price + num, itemSort);
    sort (stools, stools + numS, itemSort);
    for (int i = 0; i < min (numC, numS) ; i++) {
        whichCart[stools[i].id] = i + 1;
    }
    for (int i = numC; i < numS; i++) {
        whichCart[stools[i].id] = numC;
    }
    remC = max (0, numC - numS);
    for (int i = 0; i < num; i++) {
        if (price[i].type == 2) {
            numP++;
            if (numP > remC) {
                whichCart[price[i].id] = numC;
            } else {
                whichCart[price[i].id] = numS + numP;
            }
        }
    }
    for (int i = 1; i <= num; i++) {
        carts[whichCart[i]].push_back (i);
    }
    for (int i = 1; i <= min (numC, numS); i++) {
        minCart[i] = 2000000001;
        for (int p = 0; p < carts[i].size(); p++) {
            minCart[i] = min (minCart[i], idPrice[carts[i][p]]);
        }
        total -= (minCart[i]/2.0);
    }
    printf ("%.1lf\n", total);
    for (int i = 1; i <= numC; i++) {
        printf ("%d", carts[i].size() );
        for (int p = 0; p < carts[i].size(); p++) {
            printf (" %d", carts[i][p]);
        }
        printf ("\n");
    }
    return 0;
}