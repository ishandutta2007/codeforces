#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
vi primes;
const int N = 3e6;
int factor[N];
vi primedivs[N];
bool done[N];
void pre(){
    for(int i = 2;i*i<N;i++) if(!factor[i]) for(int j = i*i;j<N;j+=i) factor[j] = i;
    for(int i = 2;i<N;i++){
        if(!factor[i]){
            primes.pb(i);
            for(int j = i; j < N; j+= i) primedivs[j].push_back(i);
        }
    }
}
int a[N];
bool chk(int x){
    for(int p : primedivs[x]) if(done[p]) return 0;
    return 1;
}

void add(int x){
    for(int p : primedivs[x]) done[p] = 1;
}

int main(){
    pre();
    int n;
    scanf("%d", &n);
    bool ok = 1;
    for(int i = 1; i <= n; i++){
        scanf("%d", a + i);
        ok &= chk(a[i]);
        if(!ok){
            int curr = i;
            for(int j = a[i] + 1; j < N; j++) if(chk(j)){
                printf("%d ", j); add(j);
                curr++;
                break;
            }

            for(int j = 2; j < N && curr <= n; j++) if(chk(j)){
                printf("%d ", j); add(j);
                curr++;
            }
            assert(curr > n);
            return 0;
        }
        printf("%d ", a[i]);
        add(a[i]);
    }
}