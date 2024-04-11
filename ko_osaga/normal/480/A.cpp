#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int,int> pi;

int n;
pi a[5005];

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d %d",&a[i].first,&a[i].second);
    }
    sort(a,a+n);
    reverse(a,a+n);
    int low = a[0].second;
    for (int i=1; i<n; i++) {
        if(a[i].first <= low) low = a[i].first;
        else if(a[i].second <= low) low = a[i].second;
        else{
            printf("%d",a[0].first);
            return 0;
        }
    }
    printf("%d",a[0].second);
}