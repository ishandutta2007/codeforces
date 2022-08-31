#include <cstdio>
#include <set>
using namespace std;

int w,h,q;
set<int> v1, h1;
multiset<int> v2, h2;

int main(){
    scanf("%d %d %d",&w,&h,&q);
    v1.insert(0);
    v1.insert(w);
    h1.insert(0);
    h1.insert(h);
    v2.insert(w);
    h2.insert(h);
    while (q--) {
        char str[5];
        int t;
        scanf("%s %d",str,&t);
        if(str[0] == 'H'){
            auto tmp2 = h1.lower_bound(t);
            auto tmp = tmp2;
            tmp--;
            h2.erase(h2.find(*tmp2 - *tmp));
            h2.insert(*tmp2 - t);
            h2.insert(t - *tmp);
            h1.insert(t);
        }
        else{
            auto tmp2 = v1.lower_bound(t);
            auto tmp = tmp2;
            tmp--;
            v2.erase(v2.find(*tmp2 - *tmp));
            v2.insert(*tmp2 - t);
            v2.insert(t - *tmp);
            v1.insert(t);
        }
        printf("%I64d\n",1ll * *v2.rbegin() * *h2.rbegin());
    }
}