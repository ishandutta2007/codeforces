#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <numeric>
using namespace std;

const int maxn = 100000;
#define BLOCKSZ 317

int n;
struct Block {
    bool color_same;
    bool defered; // defered nasty colorfulness
    int color_all;
    int defered_op;
    long long colorfulness_sum = 0;
    long long colorfulness_diff = 0;
    long long sorted_color[BLOCKSZ];
    long long prefix_sum[BLOCKSZ + 1];

    int color[BLOCKSZ];
    long long colorfulness[BLOCKSZ];

    void push();
    void pull();
} blocks[BLOCKSZ];

// flush everything in O(BLOCKSZ)
void Block::push() {
    if(defered_op) {
        for(int i = 0; i < BLOCKSZ; i++) {
            colorfulness[i] += abs(defered_op - color[i]);
        }
        defered_op = false;
    }
    if(color_same) {
        for(int i = 0; i < BLOCKSZ; i++)
            sorted_color[i] = color[i] = color_all;
        partial_sum(sorted_color, sorted_color + BLOCKSZ, prefix_sum + 1);
        color_same = false;
    }
    if(colorfulness_diff) {
        for(int i = 0; i < BLOCKSZ; i++)
            colorfulness[i] += colorfulness_diff;
        colorfulness_diff = 0;
    }
}

// cache everything in O(BLOCKSZ)
void Block::pull() {
    colorfulness_sum = 0;
    for(int i = 0; i < BLOCKSZ; i++)
        colorfulness_sum += colorfulness[i];
    // update sorted_color
    copy_n(color, BLOCKSZ, sorted_color);
    sort(sorted_color, sorted_color + BLOCKSZ);
    // update prefix_sum
    partial_sum(sorted_color, sorted_color + BLOCKSZ, prefix_sum + 1);
}

void modify(int l, int r, int x) {
    int blockl = l / BLOCKSZ;
    int blockr = (r - 1) / BLOCKSZ + 1;

    for(int i = blockl; i < blockr; i++) {
        Block& block = blocks[i];
        if(i == blockl || i == blockr - 1) {
            block.push();
            int l2 = i == blockl ? l % BLOCKSZ : 0;
            int r2 = i == blockr - 1 ? (r - 1) % BLOCKSZ + 1 : BLOCKSZ;
            for(int j = l2; j < r2; j++) {
                int y = block.color[j];
                block.color[j] = x;
                block.colorfulness[j] += abs(x - y);
            }
            block.pull();
        } else {
            // as a whole
            if(block.color_same) {
                block.colorfulness_sum += BLOCKSZ * 1ll * abs(block.color_all - x);
                block.colorfulness_diff += abs(block.color_all - x);
                block.color_all = x;
            } else {
                int a = lower_bound(block.sorted_color, block.sorted_color + BLOCKSZ, x) - block.sorted_color;
                block.colorfulness_sum += (2LL * a - BLOCKSZ) * x + block.prefix_sum[BLOCKSZ] - 2 * block.prefix_sum[a];
                block.defered = true;
                block.defered_op = x;
                block.color_same = true;
                block.color_all = x;
            }
        }
    }
}

long long query(int l, int r) {
    long long sum = 0;
    int blockl = l / BLOCKSZ;
    int blockr = (r - 1) / BLOCKSZ + 1;

    for(int i = blockl; i < blockr; i++) {
        Block& block = blocks[i];
        if(i == blockl || i == blockr - 1) {
            block.push();
            int l2 = i == blockl ? l % BLOCKSZ : 0;
            int r2 = i == blockr - 1 ? (r - 1) % BLOCKSZ + 1 : BLOCKSZ;
            for(int j = l2; j < r2; j++) {
                sum += block.colorfulness[j % BLOCKSZ];
            }
        } else {
            sum += block.colorfulness_sum;
        }
    }
    return sum;
}

int main(){
    int m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        Block& block = blocks[i / BLOCKSZ];
        block.color[i % BLOCKSZ] = i + 1;
        block.sorted_color[i % BLOCKSZ] = i + 1;
        block.prefix_sum[i % BLOCKSZ + 1] = block.prefix_sum[i % BLOCKSZ] + i + 1;
    }
    while(m--){
        int type;
        scanf("%d", &type);
        if(type == 1) {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            l--;
            modify(l, r, x);
        } else if(type == 2) {
            int l, r;
            scanf("%d %d", &l, &r);
            l--;
            printf("%I64d\n", query(l, r));
        } else {
            fprintf(stderr, "bad type %d\n", type);
        }
    }
}