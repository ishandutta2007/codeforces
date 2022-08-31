#include <cstdio>  
#include <vector>  
using namespace std;  
  
vector<int> graph[2005];  
  
int n,d,a[2005];  
int mod = 1e9 + 7;  
  
int piv;  
int f(int x, int pa){  
    long long res = 1;  
    for (int i=0; i<graph[x].size(); i++) {  
        int pos = graph[x][i];  
        if(pos == pa) continue;  
        if(a[pos] < a[piv] || a[pos] > a[piv] + d || (a[pos] == a[piv] && pos < piv)) continue;  
        res *= 1 + f(pos,x);  
        res %= mod;  
    }  
    return (int)res;  
}  
  
int main(){  
    scanf("%d %d",&d,&n);  
    for (int i=1; i<=n; i++) {  
        scanf("%d",&a[i]);  
    }  
    for (int i=0; i<n-1; i++) {  
        int x,y;  
        scanf("%d %d",&x,&y);  
        graph[x].push_back(y);  
        graph[y].push_back(x);  
    }  
    int res = 0;  
    for (int i=1; i<=n; i++) {  
        piv = i;  
        res += f(i,0);  
        res %= mod;  
    }  
    printf("%d",res);  
}