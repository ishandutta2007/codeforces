#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
vector<int> vec = {0};
vector<ll> pref ={0LL};
double get(int i, int k){
    return k - (k + pref[i]) / ((double)i + 1.);
}

int main(){
    int q;
    sd(q);
    double ans = 0;
    for(int i = 1; i <= q; i++){
        int type;
        sd(type);
        if(type == 1){
            int k;
            sd(k);
            vec.push_back(k);
            pref.push_back(k + pref.back());
            if(vec.size() == 2) continue;
            int lo = 1, hi = vec.size() - 2;
            while(lo < hi - 1){
                int mid = (lo + hi) >> 1;
                if(get(mid, k) < get(mid + 1, k)){
                    lo = mid + 1;
                }
                else hi = mid;
            }
            for(int t = lo; t <= hi; t++) ans = max(ans, get(t, k));
        }
        else{
            printf("%.10lf\n", ans);
        }
    }
}