#include <bits/stdc++.h>
using namespace std;

const int NS = 2*(1e5)+4;
int N;
int arr[NS];
int d[NS], from[NS];
struct data{
    int num, gap;
    data(){}
    data(int a, int b):num(a), gap(b){}
    bool operator<(const data&r)const{
        return gap<r.gap||(gap==r.gap&&d[num]<d[r.num]);
    }
};
multiset < data > st;
multiset < data >::iterator p;

void out(int x){
    if(from[x]==x){
        printf("%d ", x);
        return;
    }
    out(from[x]);
    printf("%d ", x);
}

int main(){
    scanf("%d", &N);
    for(int i=1;i<=N;i++) scanf("%d", arr+i), from[i] = i;

    for(int i=1;i<=N;i++){
        d[i] = 1;
        p = st.lower_bound(data(0, arr[i]-1));
        int gap = 0, num;
        if(p!=st.end()){
            p = st.lower_bound(data(0, arr[i]));
            if(p==st.end()) p = st.end(), p--;
            else p--;
            if(p!=st.end()&&p->gap==arr[i]-1){
                if(d[p->num]>gap){
                    gap = d[p->num];
                    num = p->num;
                }
            }
        }
        if(gap+1>d[i]){
            d[i] = gap+1, from[i] = num;
        }
        st.insert(data(i, arr[i]));
    }
    int ans = 0;
    for(int i=1;i<=N;i++) ans = max(ans, d[i]);
    printf("%d\n", ans);
    for(int i=1;i<=N;i++) if(d[i]==ans){
        out(i);
        break;
    }

    return 0;
}