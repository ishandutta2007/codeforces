#include <bits/stdc++.h>

using namespace std;

const int NS = (int)2e5+4;
int N, d;
int arr[NS];
int ans[NS], M;
struct setd{
    int num, pos;
    setd(){}
    setd(int num, int pos):num(num), pos(pos){}
    bool operator<(const setd&r)const{
        return num<r.num;
    }
};
set < setd > st;
set < setd >::iterator p, pp;

int main(){
    scanf("%d %*d %d", &N, &d);
    for(int i=1;i<=N;++i) scanf("%d", arr+i), st.insert(setd(arr[i], i));
    while(!st.empty()){
        p = st.begin(), ++M;
        while(1){
            ans[p->pos] = M;
            pp = st.lower_bound(setd(p->num+d+1, 0));
            st.erase(p);
            if(pp!=st.end()) p = pp;
            else break;
        }
    }
    printf("%d\n", M);
    for(int i=1;i<=N;++i) printf("%d ", ans[i]);
    return 0;
}