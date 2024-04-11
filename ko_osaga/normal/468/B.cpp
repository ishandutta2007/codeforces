#include <cstdio>
#include <map>
#include <cstdlib>
#include <algorithm>
using namespace std;

map<int,int> mp;
map<int,int> ::iterator it1,it2;
int p[100005];
int res[100005];
int n,a,b;

void f(int x){
    if(mp.find(x) == mp.end()) return;
    if(mp.find(b-x) != mp.end() && mp.find(a-x) != mp.end()) return;
    if(mp.find(a-x) == mp.end() && mp.find(b-x) == mp.end()){
        puts("NO");
        exit(0);
    }
    if(mp.find(a-x) == mp.end()){
        it1 = mp.find(b-x);
        it2 = mp.find(x);
        res[(*it1).second] = 1;
        res[(*it2).second] = 1;
        if(it1 != it2) mp.erase(it1), mp.erase(it2);
        else mp.erase(it1);
        f(a-b+x);
    }
    else{
        it1 = mp.find(a-x);
        it2 = mp.find(x);
        res[(*it1).second] = 0;
        res[(*it2).second] = 0;
        if(it1 != it2) mp.erase(it1), mp.erase(it2);
        else mp.erase(it1);
        f(b-a+x);
    }
}

int main(){
    scanf("%d %d %d",&n,&a,&b);
    for (int i=0; i<n; i++) {
        scanf("%d",&p[i]);
        mp[p[i]] = i;
    }
    if(a == b){
        for (int i=0; i<n; i++) {
            if(mp.find(a - p[i]) == mp.end()){
                puts("NO");
                return 0;
            }
        }
    }
    else{
        for (int i=0; i<n; i++) {
            f(p[i]);
        }
    }
    puts("YES");
    for (int i=0; i<n; i++) {
        printf("%d ",res[i]);
    }
}