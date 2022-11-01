#include <cstdio>
#include <vector>
#include <utility>
#define x first
#define y second

using namespace std;

int n;
pair < int, int > coor[1005];

vector < pair < int, pair < int, int > > > move;

bool bio[1005];

void swap_row(int x, int y){
     if (x == y){
        return;
     }
     move.push_back(make_pair(1, make_pair(x, y)));
     for (int i = 0; i < n - 1; ++i){
         if (coor[i].x == x || coor[i].x == y){
            coor[i].x ^= x;
            coor[i].x ^= y;
         }
     }
}

void swap_column(int x, int y){
     if (x == y){
        return;
     }
     move.push_back(make_pair(2, make_pair(x, y)));
     for (int i = 0; i < n - 1; ++i){
         if (coor[i].y == x || coor[i].y == y){
            coor[i].y ^= x;
            coor[i].y ^= y;
         }
     }
}

int sum[1005];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i){
        scanf("%d%d", &coor[i].x, &coor[i].y);
    }
    for (int i = 0; i < n - 1; ++i){
        ++sum[coor[i].x];
    }
    for (int i = n; i; --i){
        int pos = i;
        for (int j = 1; j < i; ++j){
            if (sum[pos] < sum[j]){
               pos = j;
            }
        }
        if (i == pos){
           continue;
        }
        swap_row(i, pos);
        sum[i] ^= sum[pos];
        sum[pos] ^= sum[i];
        sum[i] ^= sum[pos];
    }
    for (int i = 1; i <= n; ++i){
        sum[i] = 100000;
    }
    for (int i = 0; i < n - 1; ++i){
        sum[coor[i].y] = min(sum[coor[i].y], coor[i].x);
    }
    for (int i = 1; i <= n; ++i){
        int pos = i;
        for (int j = i + 1; j <= n; ++j){
            if (sum[pos] > sum[j]){
               pos = j;
            }
        }
        if (pos == i){
           continue;
        }
        swap_column(i, pos);
        sum[i] ^= sum[pos];
        sum[pos] ^= sum[i];
        sum[i] ^= sum[pos];
    }
    printf("%d\n", move.size());
    for (int i = 0; i < move.size(); ++i){
        printf("%d %d %d\n", move[i].x, move[i].y.x, move[i].y.y);
    }
    return 0;
}