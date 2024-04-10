#include <cstdio>
#include <vector>
#define x first
#define y second

#include <cstdlib>

using namespace std;

int max_bit(int a){
    if (a == 0) return -1;
    return 1 + max_bit(a >> 1);
}

void imp(){
     printf("-1\n");
     exit(0);
}

void ass(int a, int b, vector < int > &v1, vector < pair < int, int > > &v2){
     v1[a] ^= v1[b];
     v2.push_back(make_pair(a, b));
}

int n;
int x[10005];
int y[10005];

vector < pair < int, int > > comm;
vector < int > nums;
void ass(int a, int b){
     ass(a, b, nums, comm);
}
void gen_min(){
     comm.clear();
     int pt = 0;
     for (int i = 30; i >= 0; --i){
         int x = -1;
         for (int j = pt; j < nums.size(); ++j) if (nums[j] & (1 << i)) x = j;
         if (x == -1) continue;
         if (x != pt){ass(pt, x); ass(x, pt); ass(pt, x);}
         for (int j = 0; j < nums.size(); ++j) if (j != pt) if (nums[j] & (1 << i)) ass(j, pt);
         ++pt;
     }
}

vector < pair < int, int > > sol;

bool kor[10005];

int main(){ // max/min set x nadskup max/min seta y (nuliranje zanemarena operacija)
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", x + i);
    for (int i = 0; i < n; ++i) scanf("%d", y + i);
    vector < pair < int, int > > c1, c2;
    vector < int > a1, a2;
    for (int i = 0; i < n; ++i){a1.push_back(x[i]); a2.push_back(y[i]);}
    nums = a1;
    gen_min();
    c1 = comm;
    a1 = nums;
    nums = a2;
    gen_min();
    c2 = comm;
    a2 = nums;
    
    sol = c1;
    
    int pos = 0; // ne gledaj prije pos
    for (int i = 0; i < n; ++i){ // trenutna budala u a2
        if (a2[i] == 0) break;
        vector < int > used;
        int x = a2[i];
        for (int j = pos; j < n; ++j){
            if (a1[j] == 0) break;
            if (x == 0) break;
            if (max_bit(x) == max_bit(a1[j])){used.push_back(j); x ^= a1[j];}
        }
        if (x) imp();
        pos = used[0] + 1;
        kor[pos - 1] = true;
        for (int j = 1; j < used.size(); ++j) ass(used[0], used[j], a1, sol);
    }
    
    pos = 0;
    for (int i = 0; i < n; ++i){
        if (!kor[i]){ass(i, i, a1, sol); continue;}
        if (i == pos){++pos; continue;}
        ass(pos++, i, a1, sol);
        ass(i, i, a1, sol);
    }
    
    for (int i = c2.size() - 1; i >= 0; --i) sol.push_back(c2[i]);
    
    printf("%d\n", sol.size());
    for (int i = 0; i < sol.size(); ++i) printf("%d %d\n", sol[i].x + 1, sol[i].y + 1);
    
    return 0;
}