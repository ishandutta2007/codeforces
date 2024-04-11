#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int,int> pi;

pi a[200005];
int n;

int main(){
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i].first);
        a[i].first += i;
        a[i].second = i;
    }
    sort(a+1,a+n+1);
    for (int i=1; i<=n; i++) {
        a[i].first -= i;
        if(i >= 2 && a[i-1].first > a[i].first){
            puts(":(");
            return 0;
        }
    }
    for (int i=1; i<=n; i++) {
        printf("%d ",a[i].first);
    }
}