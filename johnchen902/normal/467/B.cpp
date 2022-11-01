#include <cstdio>
#include <vector>
#include <bitset>
using namespace std;
int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<int> v(m);
    for(int i = 0; i < m; i++)
        scanf("%d", &(int&)v[i]);
    int x;
    scanf("%d", &x);
    int c = 0;
    for(int i = 0; i < m; i++)
        if(bitset<32>(x ^ v[i]).count() <= k)
            c++;
    printf("%d\n", c);
}