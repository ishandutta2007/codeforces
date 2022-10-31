#include <cstdio>
#include <vector>
using namespace std;
vector<int> as[100000];
int ass;

bool is_ok(int i, int j) {
    if(as[i].size() == 1)
        return true;
    if(as[j].size() == 1)
        return true;
    if(as[j].front() - as[i][as[i].size() - 2] >= 2)
        return true;
    if(as[j][1] - as[i].back() >= 2)
        return true;
    return false;
}

int main(){
    int n;
    scanf("%d", &n);
    int last = -1;
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if(a > last)
            as[ass].push_back(a);
        else
            as[++ass].push_back(a);
        last = a;
    }
    ass++;
//    for(int i = 0; i < ass; i++) {
//        for(int j = 0; j < (int) as[i].size(); j++) {
//            printf("%d ", as[i][j]);
//        }
//        puts("");
//    }
    int maxi = 0;
    for(int i = 0; i < ass; i++)
        maxi = max(maxi, (int)(as[i].size() + 1));
    for(int i = 0, j = 1; j < ass; i++, j++)
        if(is_ok(i, j))
            maxi = max(maxi, (int)(as[i].size() + as[j].size()));
    if(maxi > n) maxi = n;
    printf("%d\n", maxi);
}